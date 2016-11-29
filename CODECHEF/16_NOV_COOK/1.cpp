/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;

int main()
{
	BOOST;
	init_temp;
	// test(2);
	// cint2(a,b);
	// out(a);
	cint(t);
	while(t--)
	{
		string s;
		cin>>s;
		ll sum = 0, temp = 0;
		int length = s.length();
		for(i=0;i<length;i++)
		{
			if(s[i] == '*')
			{
				sum += (temp-1)/2;
				temp = 0;
				continue;
			}
			temp++;
		}
		sum += (temp-1)/2;
		out(sum);
	}
}