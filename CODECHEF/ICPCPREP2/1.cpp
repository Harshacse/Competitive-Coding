#include "bits/stdc++.h"
using namespace std;
#include <string.h>

int main()
{
	std::ios::sync_with_stdio(false);
	int n1,n2,i,j,length,k;
	cin>>n1>>n2;
	char s1[1000];
	vector< vector <int> >count1(n1,std::vector<int> (26,0)),count2(n2,std::vector<int> (26,0));
	for(i=0;i<n1;i++)
	{
		cin>>s1;
		length = strlen(s1);
		for(j=0;j<length;j++)
			count1[i][s1[j]-65]++;
	}
	for(i=0;i<n2;i++)
	{
		cin>>s1;
		length = strlen(s1);
		for(j=0;j<length;j++)
			count2[i][s1[j]-65]++;
	}
	int sum = 0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			int check = 1;
			for(k=0;k<26;k++)
			{
				if(count1[i][k]+count2[j][k]==0){
					check = 0;
					break;
				}
			}
			sum += check;
		}
	}
	cout<<sum<<endl;
}