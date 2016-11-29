#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll r,c,m,k,j;
		cin>>r>>c>>m>>k>>j;
		if(r*c!= (m+k+j)) 
		{
			cout<<"No\n";
			continue;
		}
		if(m%r==0)
		{
			ll a = c - m/r;
			if(k%a == 0 && j%a==0)
			 {
				cout<<"Yes\n";
				continue;
			}
		}
		if(m%c==0)
		{
			ll a = r - m/c;
			if(k%a == 0 && j%a==0) 
			{
				cout<<"Yes\n";
				continue;
			}
		}
		if(j%r==0)
		{
			ll a = c - j/r;
			if(k%a == 0 && m%a==0)
			 {
				cout<<"Yes\n";
				continue;
			}
		}
		if(j%c==0)
		{
			ll a = r - j/c;
			if(k%a == 0 && m%a==0) 
			{
				cout<<"Yes\n";
				continue;
			}
		}
		if(k%r==0)
		{
			ll a = c - k/r;
			if(m%a == 0 && j%a==0)
			 {
				cout<<"Yes\n";
				continue;
			}
		}
		if(k%c==0)
		{
			ll a = r - k/c;
			if(m%a == 0 && j%a==0) 
			{
				cout<<"Yes\n";
				continue;
			}
		}
		if(m%c==0&&k%c==0&&j%c==0)
		{
			cout<<"Yes\n";
			continue;
		}
		if(m%r==0&&k%r==0&&j%r==0)
		{
			cout<<"Yes\n";
			continue;
		}
 
		cout<<"No\n";
	}
	return 0;
}