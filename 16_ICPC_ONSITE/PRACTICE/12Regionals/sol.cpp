
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define ff first
#define ss second
#define get getchar//_unlocked
inline int inp()
{
    int n=0,s=1;
    char p=get();
    if(p=='-')
    s=-1;
    while((p<'0'||p>'9')&&p!=EOF)
    p=get();
    while(p>='0'&&p<='9')
    {
    n = (n<< 3) + (n<< 1) + (p - '0');
    p=get();
    };
    return n*s;
}
char a[20005];
int main()
{
    int i,n,j,k,l,m,t,c=0,s,f;
    char ch;
    t=inp();
    while(t--)
    {
      n=inp();k=inp();
      scanf("%s",a);
      for(i=0,c=0,s=0,f=0;a[i];i++)
      {
          c=0;
          c++;
          while(a[i]==a[i+1])
          {
              i++;c++;
          }
          if(c>=k)
          f=1;
          s+=(int)ceil((double)c/k);
      }
      if(f==0)
      printf("-1\n");
      else
      {
        printf("%d\n",s);
      }
    }
    return 0;
}