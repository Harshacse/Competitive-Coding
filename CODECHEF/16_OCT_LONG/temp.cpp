
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=(1<<17);
int arr[2*MAX];
int v[MAX];
int freq[MAX];
int idx[MAX];
int sum[MAX];
 
void B(int p,int L,int R)
{
	if(L==R) {
		arr[p]=freq[L];
		return;
	}
	int mid=(L+R)/2;
	B(2*p,L,mid);
	B(2*p+1,mid+1,R);
	arr[p]=max(arr[2*p],arr[2*p+1]);
}
 
 
int Q(int p,int L,int R,int x,int y)
{
	if(y<L || x>R) return 0;
	if(x<=L and R<=y) return arr[p];
	int mid=(L+R)/2;
	return max( Q(2*p,L,mid,x,y),Q(2*p+1,mid+1,R,x,y));
}
 
int main()
{
	int N,K;
	int i;
	while(scanf(" %d",&N)!=EOF && N) {
	        
	      scanf(" %d",&K);
	      for(i=0;i<N;i++) scanf(" %d",&v[i]);
		
	      i=0;
	      int j=i+1;
	      int cnt=0;
 
	     while(i<N) {
	      while(j<N && (v[i]==v[j])) j++; 
		freq[cnt]=j-i;
		cnt++;
	      i=j;
	     }
 
	    B(1,0,cnt-1);
	    sum[0]=freq[0];
	    for(i=1;i<cnt;i++)
		sum[i]=sum[i-1] + freq[i];
	
//	   for(i=0;i<cnt;i++) printf("%d:%d,",freq[i],sum[i]); printf("\n");
		
		while(K--) {
		  int X,Y;
		  scanf(" %d %d",&X,&Y);
		  if(X==Y) { printf("1\n"); continue; }
 
		  int idx1=distance(sum,lower_bound(sum,sum+cnt,X));
 
		  int idx2=distance(sum,lower_bound(sum,sum+cnt,Y));
		  int mx1=0,mx2=0;
		  if(sum[idx1]==X) { mx1=min(Y,sum[idx1+1])-sum[idx1] ; idx1++; }
		  else    mx1=min(sum[idx1],Y)-X +1;
 
 
		   if( sum[idx2]==Y) {
			mx2=sum[idx2] - ((idx2>0)?max(X-1,sum[idx2-1]):(X-1));
			idx2--;
		   } else {
		      mx2=Y-((idx2>0)?max(sum[idx2-1],X-1):(X-1));
			idx2--;
		   }
		  
//		   printf(" %d, %d # %d,%d \n",mx1,mx2,idx1,idx2);
 
		   int oth=Q(1,0,cnt-1,idx1+1,max(0,idx2));
		   printf("%d\n",max(max(mx1,mx2),oth));
		}
                 
		
	}
	
	return 0;
}
 