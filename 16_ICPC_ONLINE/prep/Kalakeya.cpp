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
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,j,x,r;
		cin>>n>>k;
		int para;
		int a[n+1],b[n+1];
		for(i=1;i<=n;i++)
			a[i] = i;

		if(n<2*k)
		{
			cout<<"-1\n";
			continue;
		}

		if(k==0)
		{
			for(i=1;i<=n;i++)
				cout<<a[i]<<" ";
			nl;
			continue;
		}

		x = n/(2*k);
		r = n%(2*k);

		for(i=0;i<x;i++)
		{
			para = i*2*k;
			for(j=1;j<=k;j++)
				b[para+j] = a[para+j+k];
			for(j=1;j<=k;j++)
				b[para+j+k] = a[para+j];
		}

		int temp = r;
		if(r>k)
		{
			para = 2*x*k;
			for(i=1;i<=(r-k);i++)
			{
				b[para+i] = a[para+i+k];
				b[para+i+k] = a[para+i];
			}
			int temp1;
			temp = 2*k-r;
			j = 0;
			for(i=1;i<=temp;i++)
			{
				temp1 = b[para-temp+i];
				b[para-temp+i] = a[para+r-k+i];
				b[para+r-k+i] = temp1;
			}
		}
		else
		{
			para = 2*x*k;
			int temp = b[para-k+1];
			for(i=1;i<=r;i++)
				b[para+i-k] = a[para+i];
			for(i=1;i<=k;i++)
			{
				b[para+i+r-k] = temp;
				temp++;  
			}
		}
		for(i=1;i<=n;i++)
			cout<<b[i]<<" ";
		nl;
	}
}