#include <Eigen/Dense>

using Eigen::MatrixXd;

#include<iostream>
using namespace std;
#include<vector>
#include<stdlib.h>


void print(const vector< vector <int> > &g,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<g[i][j]<<"  ";
		}
		cout<<"\n";
	}
}

void calculate(MatrixXd g,MatrixXd &d,int k,int n)
{
	int i=k,j,check=1;
	while(i!=0)
	{
		if(check==1)
		{
			if(i%2!=0)
			{
				d= g;
				check = 0;
			}
			g = g*g;
			i/=2;
		}
		else
		{
			if(i%2!=0)
				d = d*g;
			g = g*g;
			i/=2;
		}
	}
}
int main()
{
	int n,i,j;
	cin>>n;
	int m,k,x,length,temp;
	MatrixXd g(n,n),d(n,n);
	cin>>g;
	cin>>m;
	while(m--)
	{
		std::vector<int> result;
		cin>>k>>x;
		calculate(g,d,k,n);
		for(i=0;i<n;i++)
		{
			if(d[x-1][i])
			{
				result.push_back(i+1);
			}
		}
		if(result.size() == 0)
		{
			cout<<"0"<<"\n"<<"-1"<<"\n";
		}
		else
		{
			cout<<result.size()<<"\n";
			for(i=0;i<result.size();i++)
			{
				cout<<result[i]<<" ";
			}
			cout<<"\n";
		}
	}
}