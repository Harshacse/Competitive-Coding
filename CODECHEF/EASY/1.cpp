/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define min(a,b) (a>b)?b:a
#define max(a,b) (a>b)?a:b
#define nl cout<<'\n'
#define max1(a,b,c) max(max(a,b),c)
#define min1(a,b,c) min(min(a,b),c)
#define mkp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define scan(a); int a; cin>>a 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
using namespace std;

int main()
{
	int i,j,t,n;
    cin>>t;

    while(t--)
    {
    	cin>>n;
    	ll a[n];
    	map<ll,ll> b;
    	map<ll,ll>::iterator it;
    	ll product = 1,count = 1;
    	cin>>a[0];
    	for(i=1;i<n;i++)
    	{
    		cin>>a[i];
    		if(a[i]==a[i-1])
    			count++;
    		else
    		{
    			it = b.find(a[i-1]);
    			if(it == b.end())
    				b[a[i-1]] = (count*count + count)/2;
    			else
    				b[a[i-1]] = b[a[i-1]] + (count*count + count)/2;
    			count = 1;
    		}
    	}

    	i=n;
    	it = b.find(a[i-1]);
		if(it == b.end())
			b[a[i-1]] = (count*count + count)/2;
		else
			b[a[i-1]] = b[a[i-1]] + (count*count + count)/2;

		product = 1;
    	for(it=b.begin();it!=b.end();it++)
    		product = (product *(it->second))%MOD;
    	cout<<product<<endl;
    }
}
