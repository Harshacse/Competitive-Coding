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
#define init_temp int i,j,k 
#define ll_init_temp ll i,j,k
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n"
#define out2(a,b) cout<<a<<" "<<b<<"\n"
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;

int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		string a,b,c;
		cin>>a>>b>>c;
		int la = a.length();
		int dp[la+1][la+1][la+1];

		for(i=0;i<=la;i++)
		{
			for(j=0;j<=la;j++)
			{
				for(k=0;k<=la;k++)
				{
					if(i==0||j==0||k==0)
					{
						dp[i][j][k] = 0;
						continue;
					}
					if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
						dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
					else
					{
						dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k]);
						dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);
					}
				}
			}
		}

		out(3*la-3*dp[la][la][la]);
	}
}