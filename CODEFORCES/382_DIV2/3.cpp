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
#define init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;

ll n;

ll bs(ll start, ll end)
{
	ll mid = (start+end)/2;
	ll res = (mid*mid- mid +4)/2;
	ll midp = mid+1;
	ll res1 = (midp*midp- midp +4)/2;
	if(res<=n && res1>n)
		return mid;
	else if(res<=n && res1<=n)
		bs(mid+1,end);
	else if(res>n)
		bs(start,mid);
}

int main()
{
	BOOST;
	cin>>n;
	ll x;
	if(n==2)
		x = 1;
	else
		x = bs(2,2e9);
	out(x);
}