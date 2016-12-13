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
#define init_temp int i,j
#define ll_init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;

int main()
{
	init_temp;
	cint(t);
	while(t--)
	{
		cint(n);
		int x = n%8;
		int t = (n/8)*8;
		switch(x)
		{
			case 1:
				cout<<t+4<<"LB\n";
				break;
			case 2:
				cout<<t+5<<"MB\n";
				break;
			case 3:
				cout<<t+6<<"UB\n";
				break;
			case 4:
				cout<<t+1<<"LB\n";
				break;
			case 5:
				cout<<t+2<<"MB\n";
				break;
			case 6:
				cout<<t+3<<"UB\n";
				break;
			case 7:
				cout<<t+8<<"SU\n";
				break;
			case 0:
				cout<<t-1<<"SL\n";
				break;
		}
	}
}