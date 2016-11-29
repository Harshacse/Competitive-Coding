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
	int count = 0,count1 = 0,check=0;
	for(i=0;i<n;i++)
	{
		if(check==0)
		{
			if(temp[i]=='b')
				count+=1;
		}
		if(check==1)
		{
			if(temp[i]=='r')
				count1+=1;
		}
		check = (check+1)%2;
	}
	int ans1,ans2;
	ans1 = max(count,count1);
	check = 1;
	count = count1 =0;
	for(i=0;i<n;i++)
	{
		if(check==0)
		{
			if(temp[i]=='b')
				count+=1;
		}
		if(check==1)
		{
			if(temp[i]=='r')
				count1+=1;
		}
		check = (check+1)%2;
	}
	ans2 = max(count,count1);
	cout<<min(ans2,ans1)<<'\n';
}
