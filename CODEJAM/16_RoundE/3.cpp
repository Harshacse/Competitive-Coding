/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define boost std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define out(x) cout<<x<<"\n"
typedef vector<long long> vii;
#define FOR(i,a,b) for(i=(a);i<b;++i)
#define INF 1000000000000000000
#define nl cout<<"\n";

ll coin(vii a, ll n )
{
    vii dp(n+1,0);
    dp[0] = 1;
    ll i,j;
    for(i=0; i<3; i++)
        for(j=a[i]; j<=n; j++)
            dp[j] += dp[j-a[i]];

    return dp[n];
}
int main()
{
    boost;
    int t,x,c=1;
    cin>>t;
    FOR(x,0,t)
    {
        ll n,d,i;
        cin>>n>>d;
        ll tot=0;
        vii a(3);
        for(i=d; i<=n ; i+=d)
        {
            a[0]=i; a[1]=i+1; a[2]=i+2;
            tot+=coin(a,n-i);
        }
        cout<<"Case #"<<c<<": "<<tot; nl;
        c++;
    }
    return 0;
}