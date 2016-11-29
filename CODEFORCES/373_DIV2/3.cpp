#include <bits/stdc++.h>
using namespace std;
#include<math.h>
int main()
{
	int n;
	int t,j;
	cin>>n>>t;
	char string[n];
	int data[n];
	int k=0,i,dot;
	for(i=0;i<n;i++)
	{
		cin>>string[i];
		if(string[i]=='.')
		{
			data[i]=-1;
			dot=i;
		}
		else
			data[i]=(int)string[i]-48;
		//cout<<data[i];
	}
	if(t==0)
	{
		for(i=0;i<n;i++)
		{
			if(data[i]==-1)
				cout<<'.';
			else
				cout<<data[i];
		}
		cout<<'\n';
		return 0;
	}
	int step=t;
	j = -1;
	for(i=dot+1;i<n;i++)
	{
		if(data[i]>=5)
		{
			if(data[i-1]==-1)
			{
				// cout<<"check"<<endl;
				j=i-2;
				if(data[j]==9)
				{
					data[j]=0;
					k = j-1;
					while(data[k]==9&&k>0)
					{
						data[k] =0;
						k--;
					}
					data[k]+=1;
				}
				else
					data[i-2]+=1;
			}
			else
			{
				j = i-1;
				while(j>=0&&data[j]==4&&step>1)
				{
					step-=1;
					data[j]+=1;
					j-=1;
					if(data[j]==-1)
					{
						j--;
						break;
					}
					if(step==1)
						break;
				}
				if(data[j]==9)
				{
					data[j]=0;
					k = j-1;
					while(data[k]==9)
					{
						data[k] =0;
						k--;
					}
					data[k]+=1;
				}
				else
					data[j]+=1;
			}
			break;
		}
	}
	if(j==-1)
		j=n-1;
	for(i=0;i<=j;i++)
	{
		if(data[i]==-1)
			cout<<'.';
		else
			cout<<data[i];
	}
	cout<<'\n';
}