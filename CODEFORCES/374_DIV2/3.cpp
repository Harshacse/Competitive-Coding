#include "bits/stdc++.h"
using namespace std;
#include <string.h>

int main()
{
	int n,m,T;
	cin>>n>>m>>T;
	vector< vector <int> > data(n+1,vector<int>(n+1,-1));
	vector< vector <int> > aglist(n+1,vector<int>(0));
	int i;
	for(i=0;i<n;i++)
	{
		int a,b,t;
		cin>>a>>b>>t;
		data[a][b] = data[b][a] = t;
		aglist[a].push_back(b);
		aglist[b].push_back(a);
	}
	vector< pair<int,int> > counts(n,make_pair(-1,-1));
	calculate()
}