/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
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

bool isprime(ll n)
{
	bool flag = true;
  	for(ll i = 2; i <= math.sqrt(n); ++i)
  	{
		if(n%i == 0)
		{
			flag = false;
			break;
		}
  	}
  	return flag;
}

int main()
{
	init_temp;
	ll n;
	cin>>n;
	if(isprime(n))
		cout<<"1\n";
	else if(n%2==0)
		cout<<"2\n";
	else
	{
		if(isprime(n-2))
			cout<<"2\n";
		else
			cout<<"3\n";	
	}
	return 0;
}