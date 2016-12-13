/*
Author : segf
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
	int t,i,j,k,count;
	cin>>t;
	while(t--)
	{
		int n,m,d,D;
		cin>>n>>m>>d>>D;
		vector< vector <int> > v(n+1,std::vector<int> (0) );
		if(n*d > m || n*D <m )
		{
			cout<<"-1\n";
			continue;
		}
		k = m/n;
		for(i=1;i<=n;i++)
		{
			count = 0;
			for(j=i;count<(m/n);)
			{
				v[i].pb(j);
				count++;
				if(j==n)
				   j= 1;
				else
					j++;
			}
		}
		int rem = m%n;
		i=1;
		while(rem>0)
		{
			j= v[i][v[i].size()-1];
			if(j==n)
				   j= 1;
				else
					j++;
			v[i].pb(j);
			i++;
			rem--;
		}
		for(i=1; i <=n ; i++)
		{
			for(j=0 ; j<v[i].size() ; j++)
				cout<<i<< " " << v[i][j]<<"\n";
		}
	}
}