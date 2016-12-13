/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
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
#define init_temp int i,j
#define ll_init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n";
#define out2(a,b) cout<<a<<" "<<b<<"\n";
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;

int main()
{
	ll_init_temp;
	cint(t);
	while(t--)
	{
		cll2(n,k);
		vector<ll> a(n);
		map<ll,ll> count;
		map<ll,ll>::iterator it;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			it = count.find(a[i]);
			if(it == count.end())
				count[a[i]] = 1;
			else
				count[a[i]]++;
		}
		sort(a.begin(),a.end());
		it = count.begin(); 
		i = 0;
		ll sum = 0;
		while(i<n)
		{
			if(count[a[i]] > k)
				
			sum += k-count[a[i]];
			j = k-count[a[i]];
			while(j!=0)
			{
				if(it->first != a[i])
				{
					if(it->second > j)

				}
			}
			while(i<n-1 && a[i]!=a[i+1])
				i++;
			i++;
		}
	}
}