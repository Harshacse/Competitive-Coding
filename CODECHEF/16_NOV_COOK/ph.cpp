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
#define INF 1e3
#define F first
#define S second

bool arr[1001];
vii prime;

void sieve(ll n)
{
    ll i,j,k;
    for(i=2; i*i<=n; i++)
    {
        if(arr[i]==true)
        {
            for(j=i*i ; j<=n; j+=i)
                arr[j]=false;
        }
    }
    for(i=2; i<=n ; i++)
    {
        if(arr[i]==true) prime.pb(i);
    }
    /*FOR(i,0,prime.size())
    cout<<prime[i]<<" ";
    nl; */
}
int main()
{
    clock_t t1,t2;
    t1=clock();
    float diff,seconds;
    boost;
    int k,i;
    for(k=2; k<=INF; k++)
        arr[k]=true;
    sieve(INF);
    //cout<<prime.size(); nl;
    int t;
    cin>>t;
    while(t--)
    {
        int j,x,y,z,u,v,w,sum,n,ans=0,temp,p,q;
        cin>>n;
        vii a(n);
        FOR(i,0,n) cin>>a[i];
        FOR(j,0,prime.size())
        {
            int even=0;
            FOR(i,0,n)
            {
                u=0;
                while(a[i]>0 && a[i]%prime[j]==0){
                    a[i]/=prime[j];
                    u++;
                }
                if(u%2==0) even++;
            }
            if(n!=even)
                ans+=min(even,n-even);
            //cout<<"even="<<even; nl;
        }
        map<int,int> m;
        map<int,int>::iterator it;
        FOR(i,0,n)
        {
            if(a[i]>1)
            {
                it = m.find(a[i]);
                if(it==m.end())
                    m[a[i]] = 1;
                else
                    m[a[i]] ++;
            }
        }
        for(map<int,int>::iterator it=m.begin() ; it!=m.end(); it++)
        {
            ans+=min(it->S, n-it->S);
        }
        out(ans);
    }
    t2=clock();
    diff = ((float)t2-(float)t1);
    seconds = diff / CLOCKS_PER_SEC;
    cout<<"Run time:"<<seconds<<endl;
    return 0;
}