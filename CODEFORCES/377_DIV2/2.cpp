/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

int main()
{
	int i, n,k;
	cin>>n>>k;
	int a[n],b[n],c[n];

	for(i=0;i<n;i++)
		cin>>a[i];

	if(n<=2)
	{
		cout<<"0\n";
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
		return 0;
	}

	int ind = 0;
	while(ind<n-1 && k-a[ind]-a[ind+1]<=0 )
	{
		c[ind] = a[ind];
		ind++;
	}

	if(ind==n-1)
	{
		cout<<"0\n";
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
		return 0;
	}
	int mini = MOD, sum, x;

	for(x=0;x<=k-a[ind]-a[ind+1];x++)
	{
		sum = x;
		b[ind] = a[ind] + x;
		for(i=ind+1;i<n;i++)
		{
			if(k -a[i]-b[i-1]>=0)
			{
				b[i] = k-b[i-1];
				sum += k-b[i-1];
			}
			else
				b[i] = a[i];
		}
		if(sum<mini)
		{
			mini = sum;
			for(i=ind;i<n;i++)
				c[i] = b[i];
		}
	}

	mini = 0;
	for(i=0;i<n;i++)
		mini += c[i]-a[i];

	cout<<mini<<endl;
	for(i=0;i<n;i++)
		cout<<c[i]<<" ";
	cout<<"\n";
}