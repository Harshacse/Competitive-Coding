/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <cmath>
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
#define init_temp int i,j
#define ll_init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;

int main()
{
	ll_init_temp;
	cint(t);
	while(t--)
	{
		ll n;
		cin>>n;
		if(n==0)
		{
			out(n);
			continue;
		}
		if(n==1)
		{
			cout<<"INFINITY\n";
			continue;
		}
		ll sum = n - (n/2);
		ll temp,temp1;
		for(i=2;i<40;i++)
		{
			temp = pow(n,1.0/(double)i);
			temp1 = pow((double)n/2.0,1.0/(double)i);
			// cout<<temp<<" "<<temp1<<endl;
			if(pow(temp+1,i) == (double)n)
				temp++;
			if(pow(temp1+1,i) == (double)n/2.0)
				temp1++;
			if(temp == 1)
				break;
			sum += temp - temp1;
			if(2*pow(temp1,i) > (double)n && temp1>1)
				sum+=1;
		}
		out(sum);
	}
}