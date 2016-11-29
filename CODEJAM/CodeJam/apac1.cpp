#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const double EPS = 1e-8;
//const int mod = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

//#define DEBUG
ll power(ll x,ll y,ll mod){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t;
}
#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

ll nd[5005],fac[5005];
pll dp[5005];
int main(){
	int q; scanf("%d",&q);
	REP(aa,q){
		ll n,mod; scanf("%lld%lld",&n,&mod);
		fac[0]=1%mod;
		REPP(i,1,n+2) fac[i]=fac[i-1]*i%mod;
		nd[0]=0;
		nd[1]=1%mod;
		REPP(i,2,n+2) {
			ll sum=fac[i];
			REPP(j,1,i) sum=(sum-nd[j]*fac[i-j]%mod)%mod;
			nd[i]=(sum%mod+mod)%mod;
			printf("%lld\n",nd[i]);
		}
		dp[0]=mp(0,0);
		dp[1]=mp(1%mod,1%mod);
		REPP(i,2,n+1){
			ll sq=0,sum=0;
			REPP(j,1,i+1){
				sum+=nd[j]*(dp[i-j].X+fac[i-j])%mod;
				sq+=nd[j]*((dp[i-j].Y+2*dp[i-j].X+fac[i-j])%mod)%mod;
			}
			sq=(sq%mod+mod)%mod;
			sum=(sum%mod+mod)%mod;;
			dp[i]=mp(sum,sq);
		}
		printf("Case #%d: %lld\n",aa+1,(dp[n].Y%mod+mod)%mod);
	}
	return 0;
}
