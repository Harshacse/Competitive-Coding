#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#define ll long long int
int main()
{
	ll t,R,C,k,i,j,x,y,cas=1;
	cin>>t;
	while(t--)
	{
		cin>>R>>C>>k;
		vector< vector< ll > > data(R+1, vector<ll> (C+1,0) );
		vector< vector< ll > > hori(R+1, vector<ll> (C+1,0) );
		vector< vector< ll > > verti(R+1, vector<ll> (C+1,0) );
		for(i=0;i<k;i++)
		{
			cin>>x>>y;
			data[x][y] = 1;
		}
		ll width;
		for(i=0;i<R;i++)
		{
			width = 0;
			for(j=0;j<C;j++)
			{
				if(!data[i][j])
					width++;
				else
					width =0;
				hori[i][j] = width;
			}
		}
		for(j=0;j<C;j++)
		{
			width = 0;
			for(i=0;i<R;i++)
			{
				if(!data[i][j])
					width++;
				else
					width =0;
				verti[i][j] = width;
			}
		}
		ll temp = 2;
		/*
		vector<ll> rec(min(R,C)+2,0);
		rec[0]=1;
		
		for(i=1;i<min(R,C)+2;i++)
		{
			rec[i] = rec[i-1] + temp*temp;
			temp++;
		}*/
		vector< vector< ll > > check(R+1, vector<ll> (C+1,0) );
		ll sum = 0;
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				temp = ( hori[i][j] < verti[i][j] )? (hori[i][j]): (verti[i][j]);
				if(i==0||j==0)
					check[i][j] = temp;
				else
				{
					check[i][j] = min(temp,check[i-1][j-1]+1);
				}
				sum += check[i][j];
			}
		}
		cout<<"Case #"<<cas<<": "<<sum<<'\n';
		cas++;
	}
		
}