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

vector<int> primes;
void sieve()
{
	vector<int> data(100005,1);
	int i = 2,j;
	while(i<pow(10,4.6))
	{
		if(data[i] == 1)
		{
			primes.pb(i);
			j = 2*i;
			while(j<=pow(10,4.6))
			{
				data[j] = 0;
				j += i;
			}
		}
		i++;
	}
}

int bsr(vector<int> &primes, int p, int a,int left,int right)
{
	int mid = (left+right)/2;
	double loga = log(a)/log(p);
	if(mid <= 0)
		return 0;
	if((double)primes[mid]-1.0>=loga && primes[mid-1]-1.0<loga)
		return mid;
	if(mid == primes.size()-1)
		return primes.size();
	else if((double)primes[mid]-1.0>loga)
		bsr(primes,p,a,left,mid-1);
	else if((double)primes[mid]-1.0<loga)
		bsr(primes,p,a,mid+1,right);
}

int bsl(vector<int> &primes, int p, int a,int left,int right)
{
	int mid = (left+right)/2;
	double loga = log(a)/log(p);
	if(mid >= primes.size()-1)
		return (primes.size()-1);
	if((double)primes[mid]-1.0<=loga && primes[mid+1]-1.0>loga)
		return mid;
	if(mid == 0)
		return -1;
	else if((double)primes[mid]-1.0<loga)
		bsl(primes,p,a,mid+1,right);
	else if((double)primes[mid]-1.0>loga)
		bsl(primes,p,a,left,mid-1);
}

int main()
{
	// BOOST;
	init_temp;
	sieve();
	cint(t);
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int result = 0;
		for(i=0;i<primes.size();i++)
		{
			int cr = bsr(primes,primes[i],a,0,primes.size()-1);
			int cl = bsl(primes,primes[i],b,0,primes.size()-1);
			// out2(cr,cl);
			if(cl == -1)
				continue;
			if(cr == primes.size())
				continue;
			result += (cl-cr+1);
		}
		out(result);
	}
}