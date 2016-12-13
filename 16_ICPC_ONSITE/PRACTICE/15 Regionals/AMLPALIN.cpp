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

int main()
{
	init_temp;
	cint(t);
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		map<string,int> data;
		data.clear();
		map<string,int> :: iterator it;
		for(i=0;i<n;i++)
		{
			cin>>s;
			it = data.find(s);
			if(it == data.end())
				data[s] = 1;
			else
				data[s]++;
		}
		int aa = data["aa"], bb = data["bb"], ab = data["ab"], ba = data["ba"];
		if(aa%2==0)
		{
			for(i=0;i<aa/2;i++)
				cout<<"aa";
			for(i=0;i<min(ab,ba);i++)
				cout<<"ab";
			for(i=0;i<bb;i++)
				cout<<"bb";
			for(i=0;i<min(ab,ba);i++)
				cout<<"ba";
			for(i=0;i<aa/2;i++)
				cout<<"aa";
			nl;
		}
		else
		{
			for(i=0;i<aa/2;i++)
				cout<<"aa";
			for(i=0;i<min(ab,ba);i++)
				cout<<"ab";
			for(i=0;i<bb/2;i++)
				cout<<"bb";
			cout<<"aa";
			for(i=0;i<bb/2;i++)
				cout<<"bb";
			for(i=0;i<min(ab,ba);i++)
				cout<<"ba";
			for(i=0;i<aa/2;i++)
				cout<<"aa";
			nl;
		}
	}
}