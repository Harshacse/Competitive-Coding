/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j
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
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll len = s.length();
	i = 0;
	int left = 0;
	while(s[i] != 'G')
		i++;
	while(s[left] != 'T')
		left++;
	if((left-i)%k != 0)
	{
		cout<<"NO\n";
		return 0;
	}
	bool yes = true;
	if(i>left)
	{
		j = i-k;
		while(s[j]!='T')
		{
			if(s[j] == '#')
				yes = false;
			j -= k;
		}
	}
	else if(i<left)
	{
		j = i+k;
		while(s[j]!='T')
		{
			if(s[j] == '#')
				yes = false;
			j += k;
		}
	}
	if(yes)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}