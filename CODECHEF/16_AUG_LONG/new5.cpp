#include<iostream>
using namespace std;
#include<vector>
#include<stdlib.h>

void calculate(vector< vector <int> >  &A,vector< vector < vector <int> > >  &v,int k,int x,int go,int n)
{
	if(k==0)
	{
		v[x][go][k]=1;
	}
	for(int i =0;i<n;i++)
	{
		if(A[go][i])
		{
			calculate(A,v,k-1,x,i,n);
		}
	}
	
}
int main()
{
	int n,i,j,count=0;
	cin>>n;
	int m,k,x,length,temp;
	vector< vector<int> > g(n, vector<int>(n,0));
	vector< vector< vector <int> > > result(10001,vector<vector<int> >(n,vector <int>(n,0)));

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
	cin>>m;
	while(m--)
	{
		vector<int> temp;
		cin>>k>>x;
		calculate(g,result,k,x,x,n);
		count = 0;
		for(i=0;i<n;i++)
		{
			if(result[x][i][k])
			{
				count+=1;
				temp.push_back(i);
			}
		}
		if(temp.size() == 0)
		{
			cout<<"0"<<"\n"<<"-1"<<"\n";
		}
		else
		{
			cout<<temp.size()<<"\n";
			for(i=0;i<temp.size();i++)
			{
				cout<<temp[i]<<" ";
			}
			cout<<"\n";
		}
	}
}