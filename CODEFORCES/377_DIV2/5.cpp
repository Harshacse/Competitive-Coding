#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005];
int ans1[200005],ans2[200005];
map < int , vector < int > > ma;

int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",b+i);
            ma[b[i]].push_back(i);
        }

        for(int i=1;i<=m;++i)scanf("%d",a+i);
       
        int c=0,cc=0;
        for(int cnt=0;cnt<33;++cnt){
            for(int i=1;i<=m;++i){
                int x=a[i];
                if(x==0)continue;
                if(ma.count(x)){
                    ++c;
                    int nxt = ma[x].back();
                    ans1[nxt]=i;
                    ma[x].pop_back();
                    if(ma[x].empty())ma.erase(x);
                    a[i]=0;
                    ans2[i]=cnt;
                    cc+=cnt;
                }
            }
            int x=-1;
            for(int i=1;i<=m;++i){
                a[i]=(a[i]+1)/2;
                if(a[i])x=1;
            }
            if(x==-1)break;
        }
        cout<<c<<" "<<cc<<endl;
        for(int i=1;i<=m;++i){
            printf("%d ",ans2[i]);
        }
        cout<<endl;
        for(int i=1;i<=n;++i){
            printf("%d ",ans1[i]);
        }
        cout<<endl;




    }
}