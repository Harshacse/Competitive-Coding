#include "bits/stdc++.h"
using namespace std;
#include <string.h>

int main()
{
	int n,i,j;
	cin>>n;
	int num_groups = 0;
	char s[n];
	cin>>s;
	i = 0;
	vector<int> groups;
	while(i<n)
	{
		if(s[i]=='B')
		{
			j=0;
			while(s[i]=='B')
			{
				i++;
				j++;
				if(i==n)
					break;
			}
			num_groups += 1;
			groups.push_back(j);
		}
		else
			i++;
	}
	cout<<num_groups<<endl;
	for(i=0;i<groups.size();i++)
		cout<<groups[i]<<" ";
	if(num_groups)
		cout<<endl;
}