/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <stdio.h>
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
#define init_temp int i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;

int main()
{
	init_temp;
	ll n,n1,n2;
	cin>>n>>n1>>n2;
	ll t1,t2;
	t1 = min(n1,n2);
	t2 = max(n1,n2);
	vector <ll> v;
	for(i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		v.pb(x);
	}
	sort(v.rbegin(),v.rend());
	ll sum1 = 0, sum2 = 0;
	for(i=0;i<t1;i++)
		sum1 += v[i];
	for(i=t1;i<t1+t2;i++)
		sum2 += v[i];
	double ans = (double)sum1/double(t1) + double(sum2)/double(t2);
	printf("%.10f\n",ans);
}