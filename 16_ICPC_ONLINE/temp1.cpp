/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define min(a,b) (a>b)?b:a
#define max(a,b) (a>b)?a:b
#define nl cout<<'\n'
#define max1(a,b,c) max(max(a,b),c)
#define min1(a,b,c) min(min(a,b),c)
#define mkp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ll cost = 0;
		std::vector<int> v(10,0);
		for(int i=0;i<s.size();i++)
		{
			int x = s[i]-'0';
			if(v[x] == 0)
				cost += x;
			v[x]++;
		}
		cout<<cost<<"\n";
	}
}