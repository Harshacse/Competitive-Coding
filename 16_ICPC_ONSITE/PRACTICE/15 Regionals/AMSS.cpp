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


/* This function calculates (a^b)%MOD */
ll power(ll a, ll b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%MOD;
	ll temp = pow(a,b/2);
	if(b%2==0)
		return (temp*temp)%MOD;
	else
		return (a*((temp*temp)%MOD)%MOD);
}

 
ll C(ll n, ll r,std::vector<ll> f)
{
	if(n==r)
		return 1;
	if(r==0)
		return 1;
	ll temp = power(f[r],MOD-2);
	ll temp1 = power(f[n-r],MOD-2);
	// out2(temp,temp1);
	temp = (temp*temp1)%MOD;
	out2(temp,f[n]);
	return (f[n]*temp) % MOD;
}

int main()
{
	// BOOST;
	// init_temp;
	cint(t);
	vector<ll> f(5005,1);
	for (ll i=1; i<=5002;i++)
		f[i]= (f[i-1]*i) % MOD;
	out(C(4,2,f));
	while(t--)
	{
		ll n;
		cin>>n;
		ll result = 0;
		ll mult = 26;
		for(ll i=1;i<=n;i++)
		{
			ll temp = C(n,i,f)%MOD;
			temp = (temp*temp)%MOD;
			// test(temp);
			result = (result+(temp*mult)%MOD)%MOD;
			mult = (mult*25)%MOD;
		}
		// out(result);
	}	
}