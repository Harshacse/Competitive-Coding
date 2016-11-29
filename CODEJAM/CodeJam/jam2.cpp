#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <string>
using namespace std;
typedef long long int lli;
#define flp(i, n) for(i = 0; i < n; ++i)
#define tlp(t) while(t--)
#define nl cout << "\n"
#define out(a) cout << a << "\n"
//#define mod 10e8+7
#define gout(t, a) cout << "Case #" << t << ": " << a
#define vi vector<int>
#define vii vector<lli>

lli mod = 10e8+7;

lli modpow(lli base, lli exp, lli modulus) 
{
  base %= modulus;
  lli result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int temp = 1;
	tlp(t)
	{
		lli a, b, n, k;
		cin >> a >> b >> n >> k;
		lli i, j, res, ans = 0;
		for(i = 1; i <= n; ++i)
		{ 
			lli res1 = modpow(i, a, k);
			for(j = 1; j <= n; ++j) if(i != j) {res = res1 + modpow(j, b, k); if(res % k == 0) ++ans;ans = ans % mod;}
		}
		gout(temp, ans);nl;++temp;
	}
	return 0;
}