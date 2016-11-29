
int minCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight, int start, int end, int w_extra)
{
	int n = g_nodes;--start;--end;
	vector < vector<int> > graph(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) graph[g_from[i]][g_to[i]] = graph[g_to[i]][g_from[i]] = g_weight[i];
	vector <int> distStart(n, 1e9+7);
	vector<bool> reachStart(n, false);
	distStart[start] = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int min = 1e9+7, index, current;
		for (int j = 0; j < n; ++j) if(!reachStart[j] && distStart[j] <= min) {min = distStart[j];index = j;}
		current = index;
		reachStart[current] = true;
		for (int j = 0; j < n; ++j) if(!reachStart[j] && graph[current][j] && distStart[current] != 1e9+7)
			if(distStart[current] + graph[current][j] < distStart[j]) 
				distStart[j] = distStart[current]+graph[current][j];
	}
	vector <int> distEnd(n, 1e9+7);
	vector<bool> reachEnd(n, false);
	distEnd[end] = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int min = 1e9+7, index, current;
		for (int j = 0; j < n; ++j) if(!reachEnd[j] && distEnd[j] <= min) {min = distEnd[j];index = j;}
		current = index;
		reachEnd[current] = true;
		for (int j = 0; j < n; ++j) if(!reachEnd[j] && graph[current][j] && distEnd[current] != 1e9+7)
			if(distEnd[current] + graph[current][j] < distEnd[j]) 
				distEnd[j] = distEnd[current]+graph[current][j];
	}



	if(distStart[end] <= w_extra)
		return distStart[end];
	else
	{
		int ans = 1e9+7;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if(i != j && graph[i][j] == 0)
					ans = min(distStart[i]+w_extra+distEnd[j], ans);
		return ans;
	}
}
