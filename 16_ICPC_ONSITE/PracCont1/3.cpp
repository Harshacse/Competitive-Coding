/*
	Team Name : segf
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

int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		vector<int> rows(n);
		string s;
		for(i=0;i<n;i++)
		{
			cin>>s;
			int temp = 0;
			for(j=0;j<m;j++)
			{
				if(s[j] == '*')
					temp++;
			}
			rows[i] = temp;
		}
		sort(rows.begin(),rows.end());
		int num = 0;
		int temo;
		if(m%2==0)
			temo = m/2;
		else
			temo = m/2+1;
		for(i=0;i<n;i++)
		{
			if(num==k)
			{
				break;
			}
			if(rows[i]<temo)
			{
				rows[i] = m-rows[i];
				num++;
			}
			else
				break;
		}
		
		if((k-num)%2==0)
		{
			int result = 0;
			for(i=0;i<n;i++)
				result += rows[i];
			out(result);
		}
		else
		{
			sort(rows.begin(),rows.end());
			int result = m-rows[0];
			for(i=1;i<n;i++)
				result += rows[i];
			out(result);
		}
	}
}