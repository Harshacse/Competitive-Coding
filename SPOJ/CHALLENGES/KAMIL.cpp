#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define cint(a) int a; cin>>a;
#define ll long long
#define nl cout<<'\n'
#define out(x) cout<<x<<"\n"
#define FOR(i,a,b) for(int i=(a);i<b;++i)
#define mod 1000000007
#define INF 1000000000000000000
#include <string.h>

#define max(a,b,c) max(max(a,b),max(a,c))

int main()
{
	char c[4] = {'T','D','L','F'};
	char str[25];
	int result = 1;
	while(scanf("%s",str)!=EOF)
	{
		result=1;
		FOR(i,0,strlen(str))
		{
			int check = 0;
			FOR(j,0,4)
			{
				if(str[i]==c[j])
					check=1;
			}
			if(check)
				result*=2;
		}
		out(result);
	}
}