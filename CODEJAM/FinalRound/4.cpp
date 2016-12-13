#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vii;
typedef vector< vector<int> > vvi;
typedef vector< vector<long long> > vvii;
typedef pair<int,int> pi;
typedef pair<long long,long long>  pii;
typedef vector<pair<long long, long long> > vpii;
typedef vector<string> vs;
typedef vector<double> vd;

#define boost std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define nl cout<<"\n"
#define out(x) cout<<x<<"\n"
#define FOR(i,a,b) for(i=(a);i<b;++i)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define INF 1e18
#define F first
#define S second

vii v(750001,-1),s(750001,0);

int main()
{
    boost;
    clock_t t1,t2;
    t1=clock();
    float diff,seconds;
    int t;
    cin>>t;
    while(t--)
    {
        fill(v.begin(),v.end(),-1);
        fill(s.begin(),s.end(),0);
        ll n,m,k,i,j,p,q,r,x1,x2,y1,y2,y,z,ans,sum,temp,mini=INF,maxi=-INF;
        bool ok=true;
        cin>>n;
        vii a(n);
        FOR(i,0,n)
        {
            cin>>a[i];
            v[a[i]]=1;
        }
        sort(a.begin(),a.end());
        maxi=a[n-1];
        for(i=maxi ; i>=1 ;i--)
        {
            if(v[i]==-1)
            {
                s[i]=0;
            }
            else
            {
                s[i]=1;
                sum=0;
                j=2*i;
                while(j<=maxi)
                {
                    sum=(sum+s[j])%mod; j+=i;
                }
                s[i]=(s[i]+sum)%mod;
            }
        }
        ans=0;
        FOR(i,1,maxi+1)
        {
            ans=(ans+s[i])%mod;
        }
        out(ans);

    }
    t2=clock();
    diff = ((float)t2-(float)t1);
	seconds = diff / CLOCKS_PER_SEC;
	cout<<"Run time:"<<seconds<<endl;
    return 0;
}