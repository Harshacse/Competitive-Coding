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

int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		ll a,b,n,temp;
		cin>>a>>b>>n;
		int f[7];
		if(a<0)
			a += MOD;
		if(b<0)
			b += MOD;
		f[1] = a%MOD;
		f[2] = b%MOD;
		f[4] = (MOD-a)%MOD;
		f[5] = (MOD-b)%MOD;

		if(a>b)
			temp = (a-b)%MOD;
		else
			temp = (MOD+(a-b))%MOD;
		out(temp);
		f[0] = temp%MOD;
		f[3] = (MOD-temp)%MOD;
		out(f[n%6]);
	}
}