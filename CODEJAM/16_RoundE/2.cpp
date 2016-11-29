/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include "BigInt.cpp"
#define MOD 1000000007
#define ll BigInt
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

ll base;

ll check(ll mid,ll k,ll n)
{
	ll sum =0,p = 1,temp;
	for(int i=0;i<=k;i++)
	{
		temp = sum;
		sum += p;
		p*=mid;
		if(temp > sum)
			return MAXLONG;
		if(sum > n)
			return MAXLONG;
	}
	return sum;
}
bool bs(ll n,ll k,ll left,ll right)
{
	ll mid = (left+right)/2;
	if(mid==1||left>right)
		return false;
	// ll func = ((ll)pow(mid,k+1)-1)/(mid-1);
	ll func = check(mid,k,n);
	// ll rem = (pow(mid,k+1)-1)%(mid-1);
	if(func == n)
	{
		base = mid;
		return true;
	}
	if(func < n)
		bs(n,k,mid+1,right);
	else 
		bs(n,k,left,mid-1);
}

ll solve(ll n)
{
	init_temp;
	for(k=59;k>1;k--)
	{
		// ll temp ;
		// cout<<k<<" "<<temp+2;
		// nl;
		if(bs(n,k,2,n))
			break;
	}
	if(k==1)
		base = n-1;
	return base;
}

int main()
{
	BOOST;
	init_temp;
	cint(t);
	int caseno = 1;
	while(t--)
	{
		ll n;
		cin>>n;
		ll x = solve(n);
		cout<<"Case #"<<caseno<<": "<<x<<endl;
		caseno++;
	}
}