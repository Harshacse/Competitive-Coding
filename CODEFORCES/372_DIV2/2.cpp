#include "bits/stdc++.h"
using namespace std;
#include <string.h>
char s[50005];

int main()
{
	cin>>s;
	int length = strlen(s);
	vector< vector< int > > count(length+1,vector<int>(26,0));
	int i,check = -1,j;
	for(i=0;i<length;i++)
	{
		if(i!=0)
		for(j=0;j<26;j++)
			count[i][j] = count[i-1][j];
		if(s[i]!='?')
		{
			if(i==0)
				count[i][s[i]-65] = 1;
			else
				count[i][s[i]-65] = count[i-1][s[i]-65]+1;
		}
		if(i<25)
			continue;
		int temp = 1;
		for(j=0;j<26;j++)
		{
			if(i==25)
			{
				if(count[i][j]>1)
				{
					temp = 0;
					break;
				}
			}
			else
				if(count[i][j]-count[i-26][j]>1)
				{
					temp = 0;
					break;
				}
		}
		if(temp)
		{
			check = i;
			break;
		}
	}
	if(check==-1)
	{
		cout<<"-1\n";
		return 0;
	}
	for(i=0;i<check-25;i++)
		s[i] = rand()%26 + 65;
	for(i=check+1;i<length;i++)
		s[i] = rand()%26 + 65;
	int c[26]={0};
	for(i=check-25;i<=check;i++)
	{
		if(s[i]=='?')
			continue;
		c[s[i]-65]++;
	}
	j =0;
	for(i=check-25;i<=check;i++)
	{
		if(s[i]=='?')
		{
			while(c[j]==1)
				j++;
			s[i] = j+65;
			c[j] = 1;
		}
	}
	cout<<s<<endl;
}