#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,res;
		cin>>n;
		int a[n];
		int i,j;
		for(i=0;i<n;i++)
			cin>>a[i];
		if(n==2)
		{
			res = a[0]>a[1]?a[1]:a[0];
			cout<<res<<endl;
			continue;
		}
		if(n==3)
		{
			res = a[0]>a[1]?a[1]:a[0];
			res = a[2]>res?res:a[2];
			cout<<res<<endl;
			continue;	
		}
		int diff = a[1]-a[0],check0=-1;
		if(a[2]-a[1]!=a[1]-a[0])
		{
			//if(a[3]-a[2])
			if(a[3]-a[2]==a[2]-a[0])
			{
				diff = a[2]-a[0];
				check0 = 1;
			}
			if(a[3]-a[2]==a[2]-a[1])
			{
				if(check0!=-1)
				{
					check0 = a[check0]>a[0]?0:check0;
				}
				else
					check0 = 0;
				if(check0==0)
					diff = a[2]-a[1];
			}
			if(a[3]-a[1]==a[1]-a[0])
			{
				if(check0!=-1)
				{
					check0 = a[check0]>a[2]?2:check0;
				}
				else
					check0 = 2;
				if(check0==2)
					diff = a[1]-a[0];
			}
			if(check0 == -1)
			{
				cout<<"-1"<<endl;
				continue;
			}
			
			for(i=4;i<n;i++)
			{
				if(a[i]-a[i-1]!=diff)
					check0 = -1;
			}
			if(check0 == -1)
			{
				cout<<"-1"<<endl;
				continue;
			}
			else
			{
				cout<<a[check0]<<endl;
				continue;	
			}
		}
		int check = -1;
		if(a[3]-a[2]!=diff)
		{
			if(n==4)
			{
				if(a[3]-a[2]==a[2]-a[0])
				{
					res= a[1]>a[3]?a[3]:a[1];
					cout<<res<<endl;
					continue;
				}
				else
				{
					res= a[3];
					cout<<res<<endl;
					continue;	
				}
			}
			if(a[3]-a[2]!=a[2]-a[0])
			{
				check=3;
				res = a[3];
				a[3]=a[2];
			}
			else
			{
				if(a[4]-a[2]!=diff)
				{
					check = 1;
					res = a[1];
					a[1]=a[0];
					diff = a[3]-a[2];
				}
				else
				{
					check = 3;
					res = a[3];
					a[3]=a[2];
				}
			}
		}
		for(i=2;i<n;i++)
		{
			if(check<4&&check>=i)
				continue;
			if(diff==a[i]-a[i-1])
				continue;
			else
			{
				if(i==n-1)
				{
					// cout<<"check"<<endl;
					check = n-1;
					res = a[n-1];
					break;
				}
				if(diff!=a[i+1]-a[i-1])
				{
					//cout<<"check"<<i<<endl;
					check = -1;
					break;
				}
				else
				{
					if(check!=-1)
					{
						check=-1;
						break;
					}
					else
					{
						//cout<<"check"<<i<<endl;
						res = a[i];
						a[i] = a[i-1];
						check = i;
					}
				}
			}
		}
		// cout<<check<<endl;
		if(i==n && check==-1)
		{
			res = a[0]>a[n-1]?a[n-1]:a[0];
			cout<<res<<endl;
			continue;	
		}
		if(check==-1)
		{
			cout<<"-1"<<endl;
		}
		else 
		{
			cout<<res<<endl;
		}
	}
}