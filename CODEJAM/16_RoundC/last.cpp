#include <bits/stdc++.h>
using namespace std;
#define cint(a) int a;cin>>a

bool get_ans(vector< pair<int,int> > &sol, vector<int> &deleted,int n)
{
	int maxa,maxd,ia,id,t = n,i;
	while(t>0)
	{
		maxa = maxd = 0;
		for(i=0;i<n;i++)
		{
			if(deleted[i]==0)
			{
				maxa = max(maxa,sol[i].first);
				maxd = max(maxd,sol[i].second);
			}
		}
		for(i=0;i<n;i++)
		{
			if(deleted[i])
				continue;
			if(sol[i].first == maxa && sol[i].second == maxd)
				return true;
			else if(sol[i].first == maxa)
			{
				t--;
				deleted[i]=1;
			}
			else if(sol[i].second == maxd)
			{
				t--;
				deleted[i]=1;
			}
		}
	}
	return false;
}

int main()
{
	int caseno = 1;
	cint(t);
	while(t--)
	{
		cint(n);
		vector< pair<int,int> > sol(n);
		std::vector<int> deleted(n,0);
		for(int i=0;i<n;i++)
		{
			cint(x);
			cint(y);
			sol[i] = make_pair(x,y);
		}
		cout<<"Case #"<<caseno;
		if(get_ans(sol,deleted,n))
			cout<<": YES\n";
		else
			cout<<": NO\n";
		caseno ++;
	}
}