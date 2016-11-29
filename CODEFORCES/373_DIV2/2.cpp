#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	cin>>n;
	char string[n],temp[n];
	for(i=0;i<n;i++)
	{
		cin>>string[i];
		temp[i] = string[i];
	}
	int count = 0,check=0;
	for(i=0;i<n;i++)
	{
		if(check==0)
		{
			if(temp[i]=='b')
			{
				if(i+1<n)
				{
					if(temp[i+1]=='r')
					{
						temp[i] = 'r';
						temp[i+1] = 'b';
						count += 1;
					}
					else
					{
						temp[i] = 'r';
						count += 1;
					}
				}
				else
				{
					temp[i] = 'r';
					count += 1;
				}
			}
		}
		else
		{
			if(temp[i]=='r')
			{
				if(i+1<n)
				{
					if(temp[i+1]=='b')
					{
						temp[i] = 'b';
						temp[i+1] = 'r';
						count += 1;
					}
					else
					{
						temp[i] = 'b';
						count += 1;
					}
				}
				else
				{
					temp[i] = 'b';
					count += 1;
				}	
			}
		}
		check = (check+1)%2;
	}
	int count1=count;
	count = 0;
	check = 1;
	for(i=0;i<n;i++)
	{
		if(check==0)
		{
			if(string[i]=='b')
			{
				if(i+1<n)
				{
					if(string[i+1]=='r')
					{
						string[i] = 'r';
						string[i+1] = 'b';
						count += 1;
					}
					else
					{
						string[i] = 'r';
						count += 1;
					}
				}
				else
				{
					string[i] = 'r';
					count += 1;
				}
			}
		}
		else
		{
			if(string[i]=='r')
			{
				if(i+1<n)
				{
					if(string[i+1]=='b')
					{
						string[i] = 'b';
						string[i+1] = 'r';
						count += 1;
					}
					else
					{
						string[i] = 'b';
						count += 1;
					}
				}
				else
				{
					string[i] = 'b';
					count += 1;
				}	
			}
		}
		check = (check+1)%2;
	}
	// cout<<count<<" "<<count1<<endl;
	if(count>count1)
		cout<<count1<<'\n';
	else
		cout<<count<<'\n';
}