#include<bits/stdc++.h>
using namespace std;
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(
#define INF 1000000007
typedef pair<int,int> ipair;//NOTES:ipair
typedef long long int64;//NOTES:int64
 /*author flame-alchemist*/
int64 n,m1;
int ispossible(int64 x){
	int64 par=0;
	int64 k=x; 
	while(k>1){
		k=k/2;
		par++;
	}
	if(par>=m1){
		return 0;
	}
	int64 child=0;
	int64 l=2*x,r=2*x+1;
	while(l<=n){
		if(r>n){
			child+=(n-l+1);
		}
		else{
			child+=(r-l+1);
		}
		r=2*r+1;
		l=2*l;
	}
	if(child>n-m1){
		return 0;
	}
	return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&m1);
		int64 low=m1,high=m1;
		int64 s=1,e=m1;
		while((e-s)>1){
			int64 m=(s+e)>>1;
			if(ispossible(m)){
				e=m;
			}
			else{
				s=m;
			}
		}
		low=e;
		if(ispossible(s)){
			low=s;
		}
		s=m1;
		e=n;
		while((e-s)>1){
			int64 m=(s+e)>>1;
			if(ispossible(m)){
				s=m;
			}
			else{
				e=m;
			}
		}
		high=s;
		if(ispossible(e)){
			high=e;
		}
	//	cout<<low<<" "<<high<<endl;
		printf("%lld\n",high-low+1);
	}
	return 0;
} 