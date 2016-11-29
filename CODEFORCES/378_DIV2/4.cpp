/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <string>
#define MOD 1000000007
#define ll long long int
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<"\n"
#define max1(a,b,c) (max(max(a,b),c))
#define min1(a,b,c) (min(min(a,b),c))
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define scan(a); int a; cin>>a 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define init_temp int i,j,k 
#define test cout<<"check\n"
using namespace std;

int main()
{
	// BOOST;
	init_temp;
	ll n;
	cin>>n;
	std::map< pair<ll,ll> ,pair<ll,ll> > a;
	vector< vector<ll> > data(3*n,std::vector<ll>(0));
	ll ind = 0;
	map <pair<ll,ll> ,pair<ll,ll> >::iterator it;

	ll result = 0;
	ll index[2],ind_size = 0;

	for(i=0;i<n;i++)
	{
		ll x,y,z;
		vector<int> t(3);
		cin>>t[0]>>t[1]>>t[2];
		sort(t.begin(),t.end());
		x = t[2];
		y = t[1];
		z = t[0];

		
		if(result< min1(x,y,z))
		{
			result = min1(x,y,z);
			index[0] = i;
			ind_size = 1;
		}


		it = a.find(mp(x,y));
		if(it == a.end())
		{
			a[mp(x,y)] = mp(ind,i);
			data[ind].pb(z);
			ind++;
		}
		else
		{
			ll temp = a[mp(x,y)].first;
			if(data[temp].size()==1)
			{
				data[temp].pb(z);
				if(result< min1(x,y,data[temp][0]+data[temp][1]))
				{
					result = min1(x,y,data[temp][0]+data[temp][1]);	
					index[0] = a[mp(x,y)].second;
					index[1] = i;
					ind_size = 2;		
				}
			}
			else
			{
				ll maxi = max(data[temp][0],data[temp][1]);
				ll mini = min(data[temp][0],data[temp][1]);
				data[temp][0] = maxi;
				data[temp][1] = max(mini,z);
				if(result< min1(x,y,data[temp][0]+data[temp][1]))
				{
					result = min1(x,y,data[temp][0]+data[temp][1]);	
					index[0] = a[mp(x,y)].second;
					index[1] = i;
					ind_size = 2;		
				}
			}
		}
		if(x==y&&y==z&&x==z)
			continue;

		it = a.find(mp(y,z));
		if(it==a.end())
		{
			a[mp(y,z)] = mp(ind,i);
			data[ind].pb(x);
			ind++;
		}
		else
		{
			ll temp = a[mp(y,z)].first;
			if(data[temp].size()==1)
			{
				data[temp].pb(x);
				if(result< min1(y,z,data[temp][0]+data[temp][1]))
				{
					result = min1(y,z,data[temp][0]+data[temp][1]);	
					index[0] = a[mp(y,z)].second;
					index[1] = i;
					ind_size = 2;		
				}
			}
			else
			{
				ll maxi = max(data[temp][0],data[temp][1]);
				ll mini = min(data[temp][0],data[temp][1]);
				data[temp][0] = maxi;
				data[temp][1] = max(mini,x);
				if(result< min1(y,z,data[temp][0]+data[temp][1]))
				{
					result = min1(y,z,data[temp][0]+data[temp][1]);	
					index[0] = a[mp(y,z)].second;
					index[1] = i;
					ind_size = 2;		
				}
			}
		}

		if(x==y)
			continue;
		it = a.find(mp(x,z));
		if(it==a.end())
		{
			a[mp(x,z)] = mp(ind,y);
			data[ind].pb(y);
			ind++;
		}
		else
		{
			ll temp = a[mp(x,z)].first;
			if(data[temp].size()==1)
			{				
				data[temp].pb(y);
				if(result< min1(x,z,data[temp][0]+data[temp][1]))
				{
					result = min1(x,z,data[temp][0]+data[temp][1]);	
					index[0] = a[mp(x,z)].second;
					index[1] = i;
					ind_size = 2;		
				}
			}
			else
			{
				ll maxi = max(data[temp][0],data[temp][1]);
				ll mini = min(data[temp][0],data[temp][1]);
				data[temp][0] = maxi;
				data[temp][1] = max(mini,y);
				if(result< min1(x,z,data[temp][0]+data[temp][1]))
				{
					result = min1(x,z,data[temp][0]+data[temp][1]);	
					index[0] = a[mp(x,z)].second;
					index[1] = i;
					ind_size = 2;		
				}
			}
		}

		cout<<ind_size<<" "<<result;
		nl;
		for(i=0;i<ind_size;i++)
			cout<<index[i]+1<<" ";
		nl;
	}
	cout<<ind_size;
	nl;
	for(i=0;i<ind_size;i++)
		cout<<index[i]+1<<" ";
	nl;
}