#include<iostream>
using namespace std;
#include<vector>
#include<stdlib.h>

void multiply(vector< vector <int> > &a,vector< vector <int> > &b, int n)
{
	vector< vector<int> > mul(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < n; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            a[i][j] = mul[i][j];
}

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

void calculate(vector< vector <int> >  &A,int k,int n,vector< vector <int> > &D)
{
	int i,j;

	vector< vector<int> > I(n, vector<int>(n,0));
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			I[i][j] = (i==j)?1:0;
		}
	}
	if(k==1)
	{
		D = A;
		return ;
	}
	if(k==0)
	{
		D = I;
		return;
	}
	if(k%2==0)
	{
		calculate(A,k/2,n,D);
		multiply(D,D,n);
	}
	else
	{
		calculate(A,k/2,n,D);
		multiply(D,D,n);
		multiply(D,A,n);	
	}
}
int main()
{
	int n,i,j;
	cin>>n;
	int m,k,x,length,temp;
	vector< vector<int> > g(n, vector<int>(n,0));
	vector< vector<int> > d(n, vector<int>(n,0));
	vector<vector<vector<int> > > data (0,vector<vector<int> >(n,vector <int>(n,0)));

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
		std::vector<int> result;
		cin>>k>>x;
		calculate(g,k,n,d);

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