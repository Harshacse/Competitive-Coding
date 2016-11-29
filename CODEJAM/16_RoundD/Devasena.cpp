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
		return ((x*x)%mod*b)%mod;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,l;
		int n;
		cin>>n;
		ll a[n];
		ll product = 1;
		for(i=0;i<n;i++)
			cin>>a[i];
			
		vector< vector <int> > count(400, std::vector<int>(21,0) );
		int primes[79] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397};
		
		for(i=0;i<79;i++)
		{
			for(j=0;j<n;j++)
			{
				int cnt = 0;
				while(a[j]%primes[i]==0)
				{
					a[j] = a[j]/primes[i];
					cnt++;
				}
				count[primes[i]][cnt]++;
			}
		}
		
		map <ll,ll> leftprimes;
		map<ll,ll>::iterator it;
		for(i=0;i<n;i++)
		{
			if(a[i]==1)
				continue;
			it = leftprimes.find(a[i]);
    		if(it == leftprimes.end())
    			leftprimes[a[i-1]] = 1;
    		else
    			leftprimes[a[i-1]] +=1;
		}

		for(it=leftprimes.begin();it!=leftprimes.end();it++)
			product = (product*(power(it->first,power(2,it->second,MOD-1),MOD)))%MOD;

		// std::vector<ll> two(n,0);
		// two[0] = 1;

		ll gcd = product;
		for(i=0;i<79;i++)
		{
			ll x = n-count[primes[i]][j],sum = 0;
			for(j=1;j<21;j++)
			{
				for(k=0;k<count[primes[i]][j];k++)
				{
					x--;
					sum = (sum + pow(2,x,MOD-1))%(MOD-1);
				}
				gcd = (gcd * power(primes[i],sum,MOD))%MOD;
			}
			if(x!=0)
				cout<<"shit\n";
		}

		cout<<gcd<<endl;
	}
}