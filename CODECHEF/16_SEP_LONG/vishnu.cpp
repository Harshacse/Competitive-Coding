#include <bits/stdc++.h>
using namespace std;
int findmaxindex(int *arr,int n)
{
    int max=arr[0];
    int ind=0;
    for(int i=1;i<n;i++)
      {
          if(max<arr[i])
            {max=arr[i];ind=i;}
         
            
      }
      return ind;
}
int main()
{
    int t,n;
    cin>>t;
    int c[100];
    int temp[100][100];
    int hash[6][100];
    int ans[100];
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
          {cin>>c[i];
          for(int j=0;j<c[i];j++)
             cin>>temp[i][j];
          }
          memset(hash, 0, sizeof(hash[0][0]) * 6 *100);
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<c[i];j++)
                   hash[temp[i][j]-1][i]++;
              
          }
          
          for(int i=0;i<c[i];i++)
          {
              int count=0;
              for(int j=0;j<6;j++)
                 {
                     if(hash[j][i]!=0) count++;
                     
                 }
                 if(count==6)
                   ans[i]=c[i]+4;
                 else if(count==5)
                   ans[i]=c[i]+2;
                 else if(count==4)
                   ans[i]=c[i]+1;
                 else
                 {//cout<<"hi"<<' '<<'\n';
                  ans[i]=count;}
                   
           }
          int val=findmaxindex(ans,n);
          int var1=0;
          for(int i=0;i<n-1;i++)
            {
                if(ans[i]==ans[i+1])var1++;
            }
            if(var1==n-1) cout<<"tie"<<'\n';
          else if(val==0)
            cout<<"chef"<<'\n';
          else if(val>0 && val <n)
            cout<<val+1<<'\n';
          
          
          
    }
    return 0;
}