#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll power(ll a, ll b)
{
    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= 2;
    }
    return x;
}
 
long long InverseEuler(ll n)
{
    return power(n,MOD-2);
}
int main()
{
	vector<long long> f(51,1);
    for (int i=2; i<=50;i++)
        f[i]= (f[i-1]*i) % MOD;
    vector<long long> invf(51,1);
    for (int i=0; i<=50;i++)
        {
            invf[i] = InverseEuler(f[i]);
            //cout<< (invf[i]*f[i])%MOD<<endl;
        }
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll temp,e= n-1;
		ll sum=0;
		for(int i=0;i<2*e;i++) cin>>temp;
		ll r=0;
		ll m=k;
		while(k>0&&r<=e)
		{
			sum = (sum+(((f[e]*invf[e-r])%MOD)*((invf[r]*m)%MOD))%MOD)%MOD;
			m=(m*(--k))%MOD;
			r++;
		}
		cout<<sum<<"\n";
 
	}
	return 0;
} 