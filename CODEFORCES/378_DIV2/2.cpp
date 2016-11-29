/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <string>
#define MOD 1000000007
#define ll long long int
#define min(a,b) (a>b)?b:a
#define max(a,b) (a>b)?a:b
#define nl cout<<"\n"
#define max1(a,b,c) max(max(a,b),c)
#define min1(a,b,c) min(min(a,b),c)
#define mkp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define scan(a); int a; cin>>a 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define init_temp int i,j,k 
using namespace std;

int main()
{
	BOOST;
	init_temp;
	
		ll n;
		cin>>n;
		ll left = 0,right = 0;
		ll l[n],r[n];
		for(i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
			left += l[i];
			right += r[i];
		}
		ll maxi= abs(right-left),index = 0;
		ll maxi1 = maxi;
		for(i=0;i<n;i++)
		{
			ll left1 = left-l[i]+r[i];
			ll right1 = right-r[i]+l[i];
			if(abs(left1-right1)>maxi)
			{
				maxi = abs(left1-right1);
				index = i;
			}
		}
		if(maxi == maxi1)
			cout<<"0\n";
		else
			cout<<(index+1)<<"\n";
}