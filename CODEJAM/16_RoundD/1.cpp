#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int t,caseno=1;
	ll r,c;
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		ll x = (r/3)*2 + r%3;
		ll y = (c/3)*2 + c%3;
		ll sum = x*y + (r/3)*(c/3);
		cout<<"Case #"<<caseno<<": "<<sum<<endl;
		caseno++;
	}	
}