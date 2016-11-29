#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int data[n];
	for(int i=0;i<n;i++)
		cin>>data[i];
	if(n==1)
	{
		if(data[n-1]==0)
			cout<<"UP\n";
		if(data[n-1]==15)
			cout<<"DOWN\n";
		else
			cout<<"-1\n";
	}
	else
	{
		if(data[n-1]>data[n-2])
		{
			if(data[n-1]==15)
				cout<<"DOWN\n";
			else 
				cout<<"UP\n";
		}
		else
		{
			if(data[n-1]==0)
				cout<<"UP\n";
			else 
				cout<<"DOWN\n";
		}
	}
}