#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,b,m;
		ll sum = 0;
		cin>>n>>b>>m;
		while(n!=0)
		{
			if(n%2==0)
			{
				sum += m*(n/2);
				n-= n/2;
			}
			else
			{
				sum += m*((n+1)/2);
				n = (n-1)/2;
			}
			m*=2;
			sum += b;
		}
		cout<<sum-b<<endl;
	}
}