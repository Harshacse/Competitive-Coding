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
#define init_temp int i,j,k 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;

vector< vector <int> > tree(100005);
int solve(vector<int> &height, int x, int y,vector<int> &list)
{
	int i,ans = -1,check = 0;
	for(i=0;i<tree[x].size();i++)
	{
		check = check|solve(height, tree[x][i], y, list);
		ans = max(ans,height[tree[x][i]]);
		if(tree[x][i] == y)
		{
			list.pb(tree[x][i]);
			check = 1;
		}
	}

	height[x] = ans+1;
	if(check == 1)
	{
		list.pb(x);
		return 1;
	}
	return 0;
}

int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		std::vector< vector <int> > graph(n+1);
		for(i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			graph[a].pb(b);
			graph[b].pb(a);
		}

		while(q--)
		{
			int x,y;
			cin>>x>>y;
			if(x==y)
			{
				out(0);
				continue;
			}
			vector<int> visit(n+1,0);
			stack<int> s;
			s.push(x);
			visit[x] = 1;
			for(i=0;i<=n;i++)
				tree[i].clear();

			while(!s.empty())
			{
				int temp = s.top();
				s.pop();

				for(i=0;i<graph[temp].size();i++)
				{
					if(visit[graph[temp][i]] == 0)
					{
						s.push(graph[temp][i]);
						tree[temp].pb(graph[temp][i]);
						visit[graph[temp][i]] = 1;
					}
				}
			}

			std::vector<int> height(n+1,0), list;
			solve(height,x,y,list);
			int length = list.size()/2,len = list.size();

			int maxl = 0,j = 0;
			for(i=0;i<min(length,len);i++)
			{
				if(height[list[i]] >maxl)
				{
					maxl = height[list[i]];
					j = i;
				}	
			}
			out(list.size()-j-1+maxl);
		}
	}
}