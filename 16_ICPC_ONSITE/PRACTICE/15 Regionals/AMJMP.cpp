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

int dp[5005][2],a[5005];
int main()
{
   	cint(n);
   	init_temp;
   	
    for(i=1;i<=n;i++) 
    	cin>>a[i];
    for(i=1;i<=n;i++)
    {
    	for(j=i-1;j>=1;j--)
    	{
    		if(a[i]>a[j])
	        	dp[i][0] = max(dp[i][0],dp[j][1]+1);
	        else if(a[i]<a[j])
	        	dp[j][1] = max(dp[j][1],dp[i][0]+1);
    	}
    }
    
    for(i=1;i<=n;i++) 
    	cout<<max(dp[i][1],dp[i][0])<<" ";
	return 0;
} 