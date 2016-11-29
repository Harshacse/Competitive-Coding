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


ll power(ll a, ll b, ll mod)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%mod;
	ll x = power(a,b/2,mod);
	if(b%2==0)
		return (x*x)%mod;
	else
		return (((x*x)%mod)*a)%mod;
}

int getgcd(int a,int b)
{
	if(a%b==0)
		return b;
	return getgcd(b,a%b);
}

ll gcd;
void subset(int* a,int *b,int in,int n)
{
	int i;
	if(in==n)
	{
		ll temp = -1;
		ll check = 1;
		for(i=0;i<n;i++)
		{
			if(b[i]==0)
				continue;
			if(temp == -1)
				temp = a[i];
			else 
			{
				if(a[i]%temp!=0)
					check = 0;
				temp = a[i];
			}
		}
		// cout<<"} : "<<temp<<"\n";
		if(temp!=-1)
			if(check==1)
				gcd++;
		return;
	}

	b[in]=0;
	subset(a,b,in+1,n);

	b[in]=1;
	subset(a,b,in+1,n);
}

int main()
{
	int t;
	int i,j;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],b[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=0;
		}
		gcd = 0;
		subset(a,b,0,n);
		cout<<gcd<<endl;
	}
}