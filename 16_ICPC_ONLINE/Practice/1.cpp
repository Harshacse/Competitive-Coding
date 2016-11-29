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
#define scan(a); int a; cin>>a 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll sum = 0,i = 0;
		while(i<s.size())
		{
			int x = s[i] - '0';
			if(x>0 && x<10)
				sum += x;
			i++;
		}
		cout<<sum<<endl;
	}

}