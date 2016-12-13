/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <math.h>
#define MOD 1000000007
#define ll long long int
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j
#define ll_init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n"
#define out2(a,b) cout<<a<<" "<<b<<"\n"
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;

int LIS(int a[],int x,int y)
{
	int len = y-x+1,i,j;
	std::vector<int> count(y-x+1,0);
	count[y-x] = 1;
	int result = 0;
	for(i=y-x-1;i>=0;i--)
	{
		int temp = 0;
		for(j=i+1;j<=y-x;j++)
		{
			if(a[i+x]<a[j+x])
				temp = max(temp,count[j]);
		}
		count[i] = temp+1;
		result = max(result,count[i]);
		// out(count[i]);
	}
	return result;
}

int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		cint2(n,m);
		int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		while(m--)
		{
			cint2(x,y);
			out(LIS(a,x-1,y-1));
		}
	}
}