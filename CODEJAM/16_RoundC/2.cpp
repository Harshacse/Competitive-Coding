#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define ll long long
#define boost std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define nl cout<<"\n"
#define out(x) cout<<x<<"\n"
#define FOR(i,a,b) for(int i=(a);i<b;++i)
#define mod 1000000007
#define INF 1000000000000000000

ll n,m;
int r,c,rs,cs,s;
char grid[100][100];
double p,q,ans=0.0;
int mark[100][100];

double func(int x,int y,int s)
{
    if(s==0)    return 0.0;
    int exp=mark[x][y];
    double base=(grid[x][y]=='A')?p:q;
    double temp=(double)pow(1-base,exp);
    temp=temp*base;
    mark[x][y]++;
    double z=0.0,t1=0.0,t2=0.0,t3=0.0,t4=0.0;
    if(x+1<r)
    {
        t1=func(x+1,y,s-1);

    }
    if(x-1>=0)
    {
        t2=func(x-1,y,s-1);

    }
    if(y+1<c )
    {
        t3=func(x,y+1,s-1);

    }
    if(y-1>=0)
    {
        t4=func(x,y-1,s-1);

    }
    z=max(t1,t2);
    z=max(z,t3);
    z=max(z,t4);
    mark[x][y]-=1;
    return (z+temp);
}

int main()
{
    boost;
    int t,count=1;
    cin>>t;
    while(t--)
    {
        int i,j;
        cin>>r>>c>>rs>>cs>>s;
        cin>>p>>q;
        FOR(i,0,r)
        {
            FOR(j,0,c)  cin>>grid[i][j];
        }
        FOR(i,0,r)
        {
            FOR(j,0,c)  mark[i][j]=0;
        }

        double z=0.0,t1=0,t2=0,t3=0,t4=0;
        if(rs+1<r)
        {
            t1=func(rs+1,cs,s);
        }
        if(rs-1>=0)
        {
            t2=func(rs-1,cs,s);
        }
        if(cs+1<c )
        {
            t3=func(rs,cs+1,s);
        }
        if(cs-1>=0)
        {
            t4=func(rs,cs-1,s);
        }
        z=max(t1,t2);
        z=max(z,t3);
        z=max(z,t4);
        printf("Case #%d: %0.7lf\n",count,z);
        count++;
    }
    return 0;
}