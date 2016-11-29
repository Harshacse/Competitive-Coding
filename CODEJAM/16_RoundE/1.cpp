#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define boost std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define out(x) cout<<x<<"\n"
#define FOR(i,a,b) for(i=(a);i<b;++i)
#define INF 1000000000000000000
#define nl cout<<"\n";

int main()
{
    boost;
    int t,count=1;
    cin>>t;
    while(t--)
    {
        ll n,m,q,i,j,k,l,rem,quot,temp;
        string s;
        cin>>s;
        cin>>i>>j;
        l=s.length();
        ll b=0,r=0;
        quot=(j-i)/l;
        temp=0;
        FOR(k,0,s.length())
        {
            if(s[k]=='B') temp++;
        }
        ll sum;
        sum=quot*temp;
        ll st=i%l,end=j%l;
        s=s+s;
        if(end<st) end+=l;
        FOR(k,st,end+1)
        {
            if(s[k]=='B')b++;
        }
        cout<<"Case #"<<count<<": "<<(sum+b); nl;
        count++;
    }
    return 0;
}
