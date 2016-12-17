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
#define MAX 100000
using namespace std;

vector<int> tree[MAX];	// Adjacency List
std::vector<int> visited[MAX];
vector<int> level[MAX];

void DFS(int root)
{
	visited[root] = 1;
	for(int i=0; i<(int)tree[root].size(); ++i)
	{
		int v = tree[root][i];
		if(!visited[v])
		{
			level[v] = level[root] + 1;
			DFS(v);
		}
	}
	return ;
}



int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0;i<N-1;++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		tree[u].push_back(v),
		tree[v].push_back(u);
	}
	for(i=0;i<N;i++)
	{
		visited[i] = 0;
		level[i] = 0;
	}
	DFS(0);
	return 0;
}