/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
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
#define init_temp int i,j,k 
#define ll_init_temp ll i,j,k
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

bool solve(int a[],int n,int c)
{
	int i,j,count = 0;
	map<int,int> quiver;
	map<int,int>::iterator it;
	vector< vector<int> > last[n+1];
	for(i=0;i<n;i++)
		last[i].pb(0);

	int tym = 0;
	for(i=0;i<n;i++)
	{
		it = quiver.find(a[i]);
		if(it == quiver.end())
		{
			tym++;
			if(count<c)
			{
				quiver[a[i]] = 1;
				last[1].pb(a[i]);
				last[1][0]++;
				count++;
			}
			else
			{
				int temp = (quiver.begin())->second;
				int temp1 = last[temp][last[temp][0]];
				last[temp][0]--;
				quiver.erase(temp1);

			}
		}
		else
		{
			quiver[a[i]] += 1;
			last[quiver[a[i]]] = a[i];
		}
	}
}

int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		int n,m,c;
		cin>>n>>m>>c;
		int a[m];
		for(i=0;i<n;i++)
			cin>>a[i];
		solve(a,m,c);
	}
}