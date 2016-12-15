#include <bits/stdc++.h>

using namespace std;

#define  INF   4000000

vector<int> List[100000];	// Adjacency List
int Magic = 200;
int parent[18][100000];		// parent[i][j] :: '2^i'th parent of node 'j', to be used for calculating LCA
int level[100000];			// level[i] :: Level of node i, here level of the root node is 0 so on
int dist[100000]; 			// dist[i] :: distance of the nearest red node from node 'i'
vector<int> new_reds;		// temporarily stores the nodes to be painted red in a little while

void DFS(int root, bool visited[])
{
	visited[root] = true;
	for(int i=0; i<(int)List[root].size(); ++i)
	{
		int v = List[root][i];
		if(!visited[v])
		{
			parent[0][v] = root;
			for(int j=1;j<18;++j)
				parent[j][v] = parent[j-1][parent[j-1][v]];
			level[v] = level[root] + 1;
			DFS(v, visited);
		}
	}
	return ;
}

int LCA(int x, int y)
{
	if(level[x] > level[y]) swap(x,y);
	int diff = level[y] - level[x];
	while(diff)
	{
		int p = (diff&-diff);
		y = parent[(int)log2(p)][y];
		diff -= p;
	}
	if(x==y) return x;
	for(int i=17;i>=0;--i)
	{
		if(parent[i][x] != parent[i][y]){
			x = parent[i][x], 
			y = parent[i][y];
		}
	}
	return parent[0][x];
}

void initialize_LCA()
{
	bool vis[100000];
	memset(vis,0,sizeof vis);
	for(int i=0;i<18;++i) parent[i][0] = 0;
	level[0] = 0;
	DFS(0,vis);
}

int get_distance(int x, int y)
{
	int lca = LCA(x,y);
	return level[x] - level[lca] + level[y] - level[lca];
}

void BFS()
{
	bool vis[100000];
	queue<pair<int,int> > Q;
	memset(vis,0,sizeof vis);
	
	for(int i=0; i<(int)new_reds.size(); ++i)
	{
		Q.push(make_pair(new_reds[i],0));
		vis[new_reds[i]] = true;
		dist[new_reds[i]] = 0;
	}
	while(!Q.empty())
	{
		pair<int,int> v = Q.front();
		Q.pop();
		for(int i=0; i<(int)List[v.first].size(); ++i)
		{
			int c = List[v.first][i];
			if(!vis[c])
			{
				dist[c] = min(dist[c], v.second + 1);
				vis[c] = true;
				Q.push(make_pair(c,v.second+1));
			}
		}
	}
	new_reds.clear();
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
		List[u].push_back(v),
		List[v].push_back(u);
	}
	initialize_LCA();
	for(int i=0;i<N;++i)
		dist[i] = (i==0?0:INF);
	new_reds.push_back(0);
	for(int i=0;i<M;++i)
	{
		if(i%Magic == 0) BFS();
		
		int type, v;
		scanf("%d %d",&type, &v);
		--v;
		if(type == 1) new_reds.push_back(v);
		else{
			int ans = dist[v];
			for(int j=0; j<(int)new_reds.size(); ++j)
				ans = min(ans, get_distance(v, new_reds[j]));
			printf("%d\n",ans);
		}
	}
	for(int i=0;i<N;++i)
		List[i].clear();
	new_reds.clear();
	return 0;
}