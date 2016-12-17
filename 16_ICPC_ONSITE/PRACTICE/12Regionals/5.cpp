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
#define ll_init_temp ll i,j,k
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n"
#define out2(a,b) cout<<a<<" "<<b<<"\n"
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;


vector< int > tree[100010];
double result = 0;

void dfs(vector <int> &visited, vector<int> dead, int u, int counter)
{
	int i,j,k;
	if(dead[u])
		counter += 1;
	for(i=0;i<tree[u].size();i++)
	{
		if(visited[tree[u][i]]!=1)
		{
			visited[tree[u][i]] = 1;
			// out2(tree[u][i],counter);
			result += double(counter)/double(counter+1);
			dfs(visited,dead,tree[u][i],counter);
		}
	}
}
int main()
{
	int temp[1000000];
	out(std::size_t(int));
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		result = 0;
		cint(n);
		vector<int> dead(n+1);	
		vector<int> visited(n+1);
		for(i=0;i<=n;i++)
		{
			tree[i].clear();
			dead[i]=0;
			visited[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			cint2(x,y);
			tree[x].pb(y);
			tree[y].pb(x);
		}
		cint(m);
		
		for(i=0;i<m;i++)
		{
			cint(x);
			dead[x] = 1;
		}

		// std::vector<int> visited(n+1,0);
		visited[1] = 1;
		dfs(visited,dead,1,0);

		printf("%.10f\n", result);
	}
}