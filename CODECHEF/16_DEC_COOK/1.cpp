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

bool check;
void check_sum(int a[],int b[],int i)
{
	if(i==4)
	{
		int sum = 0;
		bool temp = false;
		for(int j=0;j<4;j++)
			if(b[j])
			{
				sum += a[j];
				temp = true;
			}
		if(sum == 0 && temp)
			check = true;
		return;
	}
	b[i] = 0;
	check_sum(a,b,i+1);
	b[i]=1;
	check_sum(a,b,i+1);
}
int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		int a[4];
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		int b[4] = {0};
		check = false;
		check_sum(a,b,0);
		if(check)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}