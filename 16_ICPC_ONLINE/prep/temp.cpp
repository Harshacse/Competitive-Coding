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

ll calculate(std::vector<ll> v,ll k)
{
	ll n = v.size(),one,two,i;
	if(v.size()==0)
		return 0;
	if(v.size()==1)
	{
		ll t = v[0]/k;
		if(v[0]%k!=0)
			t+=1;
		return t;
	}
	i = n-1;
	while(i>=0)
	{
		if(v[i]==0)
			v.pop_back();
		else
			break;
		i--;
		n--;
	}
	if(i==-1)
		return 0;
	vector<ll> temp =v;
	temp.erase(temp.begin());
	one = calculate(temp,k)+1;
	
	ll x = min(v.size(),k);
	for(i=0;i<x;i++)
		v[i]--;

	sort(v.rbegin(),v.rend());
	two = calculate(v,k)+1;

	return min(two,one);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,i;
	cin>>t;
	while(t--)
	{
		string s;
		ll k,n;
		cin>>s>>k;
		std::vector<ll> v(26,0);
		for(i=0;i<s.size();i++)
			v[s[i]-'a'] += 1;
		if(k==1)
		{
			cout<<s.length()<<"\n";
			continue;
		}
		clock_t tStart=clock();
		ll sum = 0;
		for(i=0;i<26;i++)
		{
			sum += v[i]/k;
			v[i] = v[i]%k;
		}
		sort(v.rbegin(),v.rend());

		i = 25;
		while(i>=0)
		{
			if(v[i]==0)
				v.pop_back();
			else
				break;
			i--;
		}
		if(i!=-1)
			sum += calculate(v,k);
		//printf("time taken : %.2fs\n", (double)(clock()-tStart)/CLOCKS_PER_SEC);
		
		cout<<sum<<"\n";
	}
}