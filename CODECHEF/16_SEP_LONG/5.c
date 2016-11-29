#include <stdio.h>
#define max(a,b) a>b?a:b
typedef struct head
{
	int lp;
	int num;
}head;

int primes[] = {2, 3, 5, 7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};

int lpd(int a)
{
	int i;
	for(i=0;i<168;i++)
	{
		if(a%primes[i] == 0)
			return primes[i];
	}
	return a;
}
head data[200002];
int n;
void build() { 
  int i;
  for (i = n; i > 0; --i) 
  {
  	if((i<<1|1) > 2*n)
  	{
  		data[i].lp = data[i<<1].lp;
  		continue;
  	}
  	// printf("%d: %d %d\n",i,i<<1,i<<1|1 );
    data[i].lp = max(data[i<<1].lp,data[i<<1|1].lp);
  }
}

void modify(int p) {  
	data[p+n].num /= data[n+p].lp;
	data[p+n].lp = lpd(data[n+p].num);
	p += n;
    for (; p > 1; p >>= 1) data[p>>1].lp = max(data[p].lp,data[p^1].lp);
}

int query(int l, int r) { 
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,data[l++].lp);
    if (r&1) res = max(res,data[--r].lp);
  }
  return res;
}

int main()
{
	int t,i,m,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d", &n,&m);
	  	for (i = 1; i <= n; ++i) 
	  	{
	  		scanf("%d", &data[n+i].num);
	  		data[n+i].lp = lpd(data[n+i].num);
	  	}
	  	build(n);
	  	int x,L,R;
	  	while(m--)
	  	{
	  		scanf("%d %d %d",&x,&L,&R);
	  		if(x)
	  			printf("%d ",query(L,R));
	  		else
	  		{
	  			for(j=L;j<=R;j++)
	  				modify(j);
	  		}
	  	}
	  	// for(i=1;i<=2*n;i++)
	  	// {
	  	// 	printf("%d: %d\n",i,data[i].lp );
	  	// }
	  	
	}
}