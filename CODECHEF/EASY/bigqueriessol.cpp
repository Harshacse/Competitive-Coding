#include<bits/stdc++.h>
using namespace std;
int arr[100002],arr2[2][100002],tree2[400002],tree5[400002],lazy2[400002],lazy5[400002],lazy[400002];

void build(int node,int start,int en)
{
    if(start==en)
    {
     int p=arr[start];
      while((p%2)==0)
      {
          tree2[node]++;
          p/=2;
      }
      while((p%5)==0)
      {
          tree5[node]++;
          p/=5;
      }
    }
    else
    {
        int mid=(start+en)/2;
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,en);
        tree2[node]=tree2[2*node+1]+tree2[2*node+2];
        tree5[node]=tree5[2*node+1]+tree5[2*node+2];
    }
}


void updaterange(int node,int start,int en,int l,int r,int i,int x,int y)
{
   if(lazy[node]!=-1)
   {
     tree5[node]=((en-start+1)*lazy5[node]+arr2[1][en-lazy[node]+1]-arr2[1][start-lazy[node]]);
     tree2[node]=((en-start+1)*lazy2[node]+arr2[0][en-lazy[node]+1]-arr2[0][start-lazy[node]]);
     if(start!=en)
     {
        lazy5[2*node+1]=lazy5[node];
        lazy5[2*node+2]=lazy5[node];
        lazy2[2*node+1]=lazy2[node];
        lazy2[2*node+2]=lazy2[node];
        lazy[2*node+1]=lazy[2*node+2]=lazy[node];
     }
     lazy5[node]=lazy2[node]=0;
     lazy[node]=-1;
   }
   if(lazy2[node]!=0 || lazy5[node]!=0)
   {
     tree5[node]+=((en-start+1)*lazy5[node]);
     tree2[node]+=((en-start+1)*lazy2[node]);
     if(start!=en)
     {
        lazy5[2*node+1]+=lazy5[node];
        lazy5[2*node+2]+=lazy5[node];
        lazy2[2*node+1]+=lazy2[node];
        lazy2[2*node+2]+=lazy2[node];
     }
     lazy5[node]=lazy2[node]=0;
     lazy[node]=-1;
   }
   if(start>en || l>en || r<start)
    return;
   if(start>=l && en<=r)
   {
     if(i==1)
     {
      tree2[node]+=((en-start+1)*x);
      tree5[node]+=((en-start+1)*y);
      if(start!=en)
     {
       lazy2[2*node+1]+=x;
       lazy2[2*node+2]+=x;
       lazy5[2*node+1]+=y;
       lazy5[2*node+2]+=y;
     }
     return;
     }
     else
     {
      tree2[node]=((en-start+1)*x+arr2[0][en-l+1]-arr2[0][start-l]);
      tree5[node]=((en-start+1)*y+arr2[1][en-l+1]-arr2[1][start-l]);
      if(start!=en)
     {
       lazy2[2*node+1]=x;
       lazy2[2*node+2]=x;
       lazy5[2*node+1]=y;
       lazy5[2*node+2]=y;
       lazy[2*node+1]=lazy[2*node+2]=l;
     }
     return;
   }
   }
   int mid=(start+en)/2;
   updaterange(2*node+1,start,mid,l,r,i,x,y);
   updaterange(2*node+2,mid+1,en,l,r,i,x,y);
   tree2[node]=tree2[2*node+1]+tree2[2*node+2];
   tree5[node]=tree5[2*node+1]+tree5[2*node+2];
}


int queryrange2(int node,int start,int en,int l,int r)
{
    if(start>en || start>r || en<l)
        return 0;
    if(lazy[node]!=-1)
   {
     tree5[node]=((en-start+1)*lazy5[node]+arr2[1][en-lazy[node]+1]-arr2[1][start-lazy[node]]);
     tree2[node]=((en-start+1)*lazy2[node]+arr2[0][en-lazy[node]+1]-arr2[0][start-lazy[node]]);
     if(start!=en)
     {
        lazy5[2*node+1]=lazy5[node];
        lazy5[2*node+2]=lazy5[node];
        lazy2[2*node+1]=lazy2[node];
        lazy2[2*node+2]=lazy2[node];
        lazy[2*node+1]=lazy[2*node+2]=lazy[node];
     }
     lazy5[node]=lazy2[node]=0;
     lazy[node]=-1;
   }
   else if(lazy2[node]!=0 || lazy5[node]!=0)
   {
     tree5[node]+=((en-start+1)*lazy5[node]);
     tree2[node]+=((en-start+1)*lazy2[node]);
     if(start!=en)
     {
        lazy5[2*node+1]+=lazy5[node];
        lazy5[2*node+2]+=lazy5[node];
        lazy2[2*node+1]+=lazy2[node];
        lazy2[2*node+2]+=lazy2[node];
     }
     lazy5[node]=lazy2[node]=0;
     lazy[node]=-1;
   }
   if(start>=l && en<=r)
    return tree2[node];
   int mid=(start+en)/2;
   return queryrange2(2*node+1,start,mid,l,r)+queryrange2(2*node+2,mid+1,en,l,r);
}


int queryrange5(int node,int start,int en,int l,int r)
{
    if(start>en || start>r || en<l)
        return 0;
    if(lazy[node]!=-1)
   {
     tree5[node]=((en-start+1)*lazy5[node]+arr2[1][en-lazy[node]+1]-arr2[1][start-lazy[node]]);
     tree2[node]=((en-start+1)*lazy2[node]+arr2[0][en-lazy[node]+1]-arr2[0][start-lazy[node]]);
     if(start!=en)
     {
        lazy5[2*node+1]=lazy5[node];
        lazy5[2*node+2]=lazy5[node];
        lazy2[2*node+1]=lazy2[node];
        lazy2[2*node+2]=lazy2[node];
        lazy[2*node+1]=lazy[2*node+2]=lazy[node];
     }
     lazy5[node]=lazy2[node]=0;
     lazy[node]=-1;
   }
   else if(lazy2[node]!=0 || lazy5[node]!=0)
   {
     tree5[node]+=((en-start+1)*lazy5[node]);
     tree2[node]+=((en-start+1)*lazy2[node]);
     if(start!=en)
     {
        lazy5[2*node+1]+=lazy5[node];
        lazy5[2*node+2]+=lazy5[node];
        lazy2[2*node+1]+=lazy2[node];
        lazy2[2*node+2]+=lazy2[node];
     }
     lazy5[node]=lazy2[node]=0;
     lazy[node]=-1;
   }
   if(start>=l && en<=r)
    return tree5[node];
   int mid=(start+en)/2;
   return queryrange5(2*node+1,start,mid,l,r)+queryrange5(2*node+2,mid+1,en,l,r);
}


int main()
{
    long long int ans;
    int t,n,m,i,l,r,x,p,y;
  for(i=1;i<100002;++i)
  {
    arr2[0][i]=arr2[0][i-1];
    arr2[1][i]=arr2[1][i-1];
    p=i;
      while((p%2)==0)
      {
          arr2[0][i]++;
          p/=2;
      }
      while((p%5)==0)
      {
          arr2[1][i]++;
          p/=5;
      }
  }
  scanf("%d",&t);
  while(t--)
  {
    for(i=0;i<300002;++i)
    {
        lazy[i]=-1;
        lazy2[i]=lazy5[i]=0;
        tree2[i]=tree5[i]=0;
    }
      ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;++i)
        scanf("%lld",&arr[i]);
    build(0,0,n-1);
    while(m--)
    {
      scanf("%d %d %d",&i,&l,&r);
      if(i!=3)
      {
        x=y=0;
        scanf("%d",&p);
        while((p%2)==0)
      {
          x++;
          p/=2;
      }
      while((p%5)==0)
      {
          y++;
          p/=5;
      }
      }
      if(i==3)
        ans+=min(queryrange2(0,0,n-1,l-1,r-1),queryrange5(0,0,n-1,l-1,r-1));
      else
        updaterange(0,0,n-1,l-1,r-1,i,x,y);
    }
    printf("%lld\n",ans);
  }
    return 0;
}