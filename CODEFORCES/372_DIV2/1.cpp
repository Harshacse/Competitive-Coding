#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,c;
	cin>>n>>c;
	int i,x,count=0,y=0;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x-y<=c)
			count+=1;
		else
			count = 1;
		y = x;
	}
	cout<<count<<endl;
}