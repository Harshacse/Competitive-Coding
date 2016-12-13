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
#define init_temp int i,j
#define ll_init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n";
#define out2(a,b) cout<<a<<" "<<b<<"\n";
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define MAX 10000007
using namespace std;

//Sieve of eratosthenes code lifted from Internet. Refer to link http://codeforces.com/blog/entry/7262
bool v_[MAX];
int len, sp[MAX];

void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (ll i = 3; i < MAX; i += 2){
		if (!v_[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < MAX; j += 2){
				if (!v_[j*i])	v_[j*i] = true, sp[j*i] = i;
			}
		}
	}
}


int main()
{
	init_temp;
	Sieve();
	cint(t);
	while(t--)
	{
		int result = 0;
		std::vector<int> count(10000005,0);
		cint(n);
		int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		
		for(i=n-1;i>=0;i--)
		{
			int temp = 0;
			vector<int> v;
			int x;
			while(a[i]!=1)
			{
				x = sp[a[i]];
				while(a[i]%x==0)
					a[i]/=x;
				v.pb(x);
				temp = max(temp,count[x]+1);
			}
			for(j=0;j<v.size();j++)
				count[v[j]] = temp;
			result = max(result,temp);
		}
		if(!result)
			result = 1;
		out(result);	
	}
}