#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#define cint(a) int a; cin>>a;

int main()
{
	cint(n);
	cint(m);
	cint(qu);
	int i,j;
	int sum=0;
	vector< vector<int> > data(n+1,std::vector<int>(n+1,0) );
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>data[i][j];
			sum += (data[i][j]==1)?1:0;
		}
	}
	n = m;
	while(qu--)
	{
		cint(x);
		cint(y);
		queue<int> q;
		if(data[x][y])
			q.push(x*n+y);
		while(!q.empty())
		{
			sum -= 1;
			int temp = q.front();
			q.pop();
			x = temp/n;
			y = temp%n;
			data[x][y] = 0;
			vector<int> temp1,temp2;
			if(x>1)
				temp1.push_back(x-1);
			if(x<n)
				temp1.push_back(x+1);
			if(y>1)
				temp2.push_back(y-1);
			if(y<n)
				temp2.push_back(y+1);
			for(i=0;i<temp1.size();i++)
			{
				for(j=0;j<temp2.size();j++)
				{
					if(data[temp1[i]][temp2[j]])
					{
						q.push(temp1[i]*n+temp2[i]);
					}
				}
			}
			for(i=0;i<temp1.size();i++)
			{
				if(data[temp1[i]][y])
				{
					q.push(temp1[i]*n+y);
				}
			}
			for(i=0;i<temp2.size();i++)
			{
				if(data[x][temp2[i]])
				{
					q.push(x*n+temp2[i]);
				}
			}
		}
		cout<<sum<<endl;
	}
}