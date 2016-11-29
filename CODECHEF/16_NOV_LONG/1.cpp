/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/
 
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int 
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp ll i,j,k 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;
 
ll gcd(ll a,ll b)
{
  ll x = max(a,b);
  ll y = min(a,b);
  if(x%y==0)
    return y;
  return gcd(y,x%y);
}
 
int main()
{
  BOOST;
  init_temp;
  cint(t);
  while(t--)
  {
    cint(n);
    std::vector<ll> v(n);
    ll mini1 = MAXINT,mini2 = mini1;
    cin>>v[0]>>v[1];
    mini1 = min(v[0],v[1]);
    mini2 = max(v[0],v[1]);
    for(i=2;i<n;i++)
    {
      cin>>v[i];
      if(v[i] <= mini1)
      {
        mini2 = mini1;
        mini1 = v[i];
      }
      else if(v[i]<mini2)
        mini2 = v[i];
    }
    ll limit = (mini1*mini2)/gcd(mini1,mini2);
    vector<ll> check;
    for(i=0;i<n;i++)
    {
      if(v[i]<=limit)
        check.pb(v[i]);
    }
 
    ll result = limit;
 
    for(i=0;i<check.size();i++)
    {
      for(j=i+1;j<check.size();j++)
      {
        ll temp = (check[i]*check[j])/gcd(check[i],check[j]);
        result = min(result,temp);
      }
    }
 
    cout<<result<<endl;
  }
} 