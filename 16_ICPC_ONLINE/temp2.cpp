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
#define max1(a,b,c) max(max(a,b),c)
#define min1(a,b,c) min(min(a,b),c)
#define mkp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,d,i,j;
	cin>>n>>d;
	ll mac=0;
	std::vector<ll> a(n,0);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		mac = max(mac,a[i]);
	}
	while(d--)
	{
		int type,x,y;
		cin>>type>>x>>y;
		if(type==1)
		{
			a[x-1] += y;
			mac = max(mac,a[x-1]);
		}
		if(type==2)
		{
			if(a[x-1]>a[y-1])
			{
				a[x-1]+=a[y-1];
				a[y-1] =0;
				// mac = max(mac,a[x-1]);
			}
			else if(a[x-1]<a[y-1])
			{
				a[y-1]+=a[x-1];
				a[x-1] =0;
				// mac = max(mac,a[y-1]);
			}
			mac = max1(a[x-1],a[y-1],mac);
		}
		// for(j=0;j<n;j++)
		// 	cout<<a[j]<<" " ;
		cout<<mac;nl;
	}
}