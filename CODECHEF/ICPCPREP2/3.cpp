#include <bits/stdc++.h>
using namespace std;

void calculate(std::vector< std::vector<int> > &data,std::vector< std::vector<int> > &res,char *a,int n,int i,std::vector< std::vector<int> > &check)
{
	int j;
	int ans = 0,ans1=0,count=0;
	for(j=0;j<data[i].size();j++)
	{
		if(check[i][ data[i][j] ]==1)
			Ncontinue;
		check[i][ data[i][j] ]=1;
		check[ data[i][j] ][i]=1;

		calculate(data,res,a,n,data[i][j],check);

		ans = max(ans,res[data[i][j]][0]^a[i]);
		ans1 = max(ans1,res[data[i][j]][1]);
		count+=1;
	}
	if(count==0)
	{
		res[i][0] = res[i][1] = a[i];
		return;
	}	
	res[i][0] = ans;
	res[i][1] = max(ans,ans1);
}

int main()
{
	int n,x,y;
	cin>>n;
	char s[n+1];
	cin>>s;
	vector< vector<int> > data(n+1,vector<int>(0) );
	vector< vector<int> > check(n+1,vector<int>(n+1,0) );
	std::vector< std::vector<int> > res(n+1,std::vector<int>(2,0) );
	int i;
	for(i=0;i<n-1;i++)
	{
		cin>>x>>y;
		data[x].push_back(y);
		data[y].push_back(x);
	}
	calculate(data,res,s,n,1,check);
	for(i=1;i<=n;i++)
		cout<<res[i][1]<<endl;
}