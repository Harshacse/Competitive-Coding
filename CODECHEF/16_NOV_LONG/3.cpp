/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int 
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp ll i,j,k 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;

ll power(ll a, ll b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%MOD;
	ll half = power(a,b/2);
	if(b%2==0)
		return (half*half)%MOD;
	else
		return (half*half*a)%MOD;
}
int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		cint(n);
		if(n<=2)
		{
			cout<<"0\n";
			continue;
		}
		ll x = power(2,n-1)-2;
		out(x);		
	}
}