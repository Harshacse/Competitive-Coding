#include<iostream>
using namespace std;

int main()
{
	long n,i,j,max;
	cin>>n;
	long a[n],ans;
	for(i=0;i<n;i++)
		cin>>a[i];
	ans = 0;
	for(i=0;i<n;i++)
	{
		max = a[i];
		for(j=i+1;j<n;j++)
		{
			long temp = a[i]&a[j];
			// cout<<a[i]<<"&"<<a[j]<<" = "<<temp<<'\n';
			if(a[j]>max)
				max = a[j];
			if(temp == a[i] || temp == a[j])
			{
				ans += max;
				// cout<<"("<<i<<","<<j<<")"<<'\n';
			}
		}
	}
	cout << ans<<'\n';
}