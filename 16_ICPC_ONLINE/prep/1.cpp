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
	// for(i=0;i<v.size();i++)
	// 	cout<<v[i]<<" "<<i<<endl;
	if(v.size()==0)
		return 0;
	if(v.size()==1)
	{
		ll t = v[0]/k;
		if(v[0]%k!=0)
			t+=1;
		// cout<<"t = "<<t<<endl;
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
	// cout<<"size is "<<v.size()<<endl;
	if(i==-1)
		return 0;
	
	vector<ll> temp ;
	//temp[0] -= k;
	// cout<<temp[0]<<endl;
	//if(temp[0]<=0)
	//	temp.erase(temp.begin());
	for(i=0;i<v.size();i++)
	{
		if(i==0)
		{
			int t1 = v[0] - k;
			if(t1>0)
				temp.pb(t1);
		}
		else
			temp.pb(v[i]);
	}
	sort(temp.rbegin(),temp.rend());
	// cout<<temp.size()<<"  shj "<<endl;
	one = calculate(temp,k)+1;
	 //cout<<one<<" ///";
	//nl;
	ll x = min(v.size(),k);
	// for(i=0;i<v.size();i++)
	// 	cout<<v[i]<<" "<<i<<endl;
	for(i=0;i<x;i++)
		v[i]--;

	// cout<<"check 111 1"<<endl;
	sort(v.rbegin(),v.rend());
	
	// cout<<v.size()<<"yo"<<endl;
	two = calculate(v,k)+1;
	//cout<<"two="<<two<<"\n";
	return min(two,one);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,i;
	cin>>t;
	while(t--)
	{
		string s;
		ll k,n;
		cin>>s>>k;
		if(k==1)
		{
			cout<<s.size()<<"\n";
			continue;
		}
		//clock_t tStart=clock();
		std::vector<ll> v(26,0);
		for(i=0;i<s.size();i++)
			v[s[i]-'a'] += 1;
		ll sum = 0;
		i = 25;
		sort(v.rbegin(),v.rend());
		while(i>=0)
		{
			if(v[i]==0)
				v.pop_back();
			else
				break;
			i--;
		}
		//for(i=0 ; i<v.size() ;i++)
		//	cout<<v[i]<<" ";
		//nl;
		sum += calculate(v,k);
		//printf("time taken : %.2fs\n", (double)(clock()-tStart)/CLOCKS_PER_SEC);
		cout<<sum<<"\n";

	}
}