#include <iostream>
using namespace std;
#include <queue> 
#define max(a,b) a>b?a:b
 
typedef struct head
{
	std::queue<int> myqueue;
	int num;
}head;
 
 

int n;
int primes[] = {2, 3, 5, 7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
 
void lpd(head data[],int a,int j)
{
	int i;
	for(i=0;i<168&&a!=0;i++)
	{
		while(a%primes[i] == 0)
		{
			a = a/primes[i];
			data[j].myqueue.push(primes[i]);
		}
	}
	if(a)
		data[j].myqueue.push(a);
	return ;
}
 
void build(head data[]) { 
  int i;
  for (i = n; i > 0; --i) 
  {
  	if((i<<1|1) > 2*n)
  	{
  		data[i].myqueue.push(data[i<<1].myqueue.front());
  		continue;
  	}
  	// printf("%d: %d %d\n",i,i<<1,i<<1|1 );
    data[i].myqueue.push(max(data[i<<1].myqueue.front(),data[i<<1|1].myqueue.front()));
  }
}

void build_int(head data[])
{
	int i;
	  for (i = n; i > 0; --i) 
	  {
	  	if((i<<1|1) > 2*n)
	  	{
	  		data[i].myqueue.pop();
	  		data[i].myqueue.push(data[i<<1].myqueue.front());
	  		continue;
	  	}
	  	// printf("%d: %d %d\n",i,i<<1,i<<1|1 );
	    data[i].myqueue.pop();
	    data[i].myqueue.push(max(data[i<<1].myqueue.front(),data[i<<1|1].myqueue.front()));
	  }	
} 
void modify(head data[],int p) {  
	data[p+n].num /= data[n+p].myqueue.front();
	data[p+n].myqueue.pop();
	if(data[p+n].myqueue.empty())
	{
		data[p+n].myqueue.push(1);
	}
	p += n;
    for (; p > 1; p >>= 1) 
    {
    	data[p>>1].myqueue.pop();
    	data[p>>1].myqueue.push(max(data[p].myqueue.front(),data[p^1].myqueue.front()));
    }
}
 
int query(head data[],int l, int r) { 
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,data[l++].myqueue.front());
    if (r&1) res = max(res,data[--r].myqueue.front());
  }
  return res;
}
 
int main()
{
	int t,i,m,j;
	cin>>t;
	while(t--)
	{
		std::queue<int> empty;   			
		cin>>n>>m;
		head data[2*n+5];
	  	for (i = 1; i <= n; ++i) 
	  	{
	  		cin>>data[n+i].num;
	  		// std::swap(data[i].myqueue,empty);
	  		// std::swap(data[i+n].myqueue,empty);
	  		lpd(data,data[n+i].num,n+i);
	  	}
	  	build(data);
	  	int x,L,R;
	  	// for(i=1;i<=2*n;i++)
	  	// {
	  	// 	cout<<i<<" : "<<data[i].myqueue.front()<<endl;;
	  	// }
	  	while(m--)
	  	{
	  		cin>>x>>L>>R;
	  		if(x)
	  		{
	  			build_int(data);
	  			cout<<query(data,L,R)<<" ";
	  		}
	  		else
	  		{
	  			for(j=L;j<=R;j++)
	  			{
	  				data[j+n].num /= data[n+j].myqueue.front();
					data[j+n].myqueue.pop();
					if(data[j+n].myqueue.empty())
					{
						data[j+n].myqueue.push(1);
						//cout<<"check  ";
					}
	  				//modify(j);
	  			}
	  		}
	  	}
	  	cout<<endl;
	}
}