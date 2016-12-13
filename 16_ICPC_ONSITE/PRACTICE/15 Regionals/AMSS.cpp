/*
	Author : Ponnada Harsha Vardhan
	Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
#define ll_init_temp ll i,j,k
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n"
#define out2(a,b) cout<<a<<" "<<b<<"\n"
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;

vector<ll> fac(5005,1);
vector<ll> inverse(5005,1);

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%MOD;
	ll small = power(a,b/2);
	ll temp = (small*small)%MOD;
	if(b%2==0)
		return temp;
	else
	{
		ll temp1 = (a*temp)%MOD;
		return temp1;
	}
}

ll C(ll n,ll i)
{
	if(n==i)
		return 1;
	if(i==0)
		return 1;
	ll temp = inverse[i], temp1 = inverse[n-i];
	ll result = (temp*temp1)%MOD;
	result = (result*fac[n])%MOD;
	return result;
}

int main()
{
	BOOST;
	ll_init_temp;
	for(i=1;i<=5000;i++)
		fac[i] = (i*fac[i-1])%MOD;
	for(i=0;i<=5000;i++)
		inverse[i] = power(fac[i],MOD-2);
	cint(t);
	while(t--)
	{
		cll(n);
		ll result = 0, fac = 26;
		ll temp;
		for(i=1;i<=n;i++)
		{
			temp = C(n,i);
			temp = (temp*temp)%MOD;
			temp = (temp*fac)%MOD;
			result = (result + temp)%MOD;
			fac = (fac*25)%MOD;
		}
		out(result);
	}
}