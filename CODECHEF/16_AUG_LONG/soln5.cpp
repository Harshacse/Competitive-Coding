#include<bits/stdc++.h>
using namespace std;
int a[501][501],n;
int mp[70][501];
int check(int h)
{
    for(int i=0;i<h;i++)
    {
        int c=0;
       for(int j=0;j<n;j++) if(mp[i][j]==mp[h][j]) c++;
       if(c==n) return i;
    }
    return -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    int m;
    cin>>m;
    while(m--)
    {
        int k,x,r=-1,flag=0;
        cin>>k>>x;
        int h=0;
        for(int i=0;i<70;i++) for(int j=0;j<n;j++) mp[i][j]=0;
        mp[h++][x-1]=1;
        while(k)
        {
            int count =0;
            for(int m=0;m<n;m++)
            {
                if(mp[h-1][m]) for(int i=0;i<n;i++) if(a[m][i]) {mp[h][i]=1;count++;}
            }
            r= check(h);
            if(r!=-1)
            {
                break;
            }
            k--;
            if(count==0) {cout<<"0\n-1\n";flag=1;}
            h++;
        }
        if(flag==1) continue;
        if(k==0)
        {
            int cat=0;
            for(int i=0;i<n;i++) if(mp[h-1][i]) cat++;
            cout<<cat<<"\n";
            for(int i=0;i<n;i++) if(mp[h-1][i]) cout<<i+1<<" ";cout<<"\n";
        }
        else
        {
            k--;
            int cat=0;
            for(int i=0;i<n;i++) if(mp[r+k%(h-r)][i]) cat++;
            cout<<cat<<"\n";
            for(int i=0;i<n;i++) if(mp[r+k%(h-r)][i]) cout<<i+1<<" ";cout<<"\n";
        }
 
    }
}
 