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
#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032
#define sq(x) ((x)*(x))
#define mset(x,v) memset(x, v , sizeof(x))
#define chkC(x,n) (x[n >> 6] & (1 << ((n >> 1) & 31)))
#define setC(x,n) (x[n >> 6] |= (1 << ((n >> 1) & 31)))
using namespace std;
unsigned base[MAX/64], segment[RNG/64], primes[LEN];
 
/* 
 * Generates all the necessary prime numbers and marks them in base[]
 */
void sieve()
{
    unsigned i, j, k;
    for (i = 3; i < LMT; i += 2)
    {
        if (!chkC(base, i))
        {    
            for (j = i * i, k = i << 1; j < MAX; j += k)
                setC(base, j);
        }
    }
    for (i = 3, j = 0; i < MAX; i += 2)
    {
        if (!chkC(base, i))
            primes[j++] = i;
    }
}
 
/*
 * Returns the prime-count within range [a,b] and marks them in segment[] 
 */
int segmented_sieve(int a, int b)
{
    unsigned i, j, k, cnt = (a <= 2 && 2 <=b )? 1 : 0;
    if (b < 2) 
        return 0;
    if (a < 3) 
        a = 3;
    if (a % 2 == 0) 
        a++;
    mset (segment, 0);
    for (i = 0; sq(primes[i]) <= b; i++)
    {
        j = primes[i] * ((a + primes[i] - 1) / primes[i]);
        if (j % 2 == 0) j += primes[i];
        for (k = primes[i] << 1; j <= b; j += k)
        {
            if (j != primes[i])
                setC(segment, (j - a));
        }
    }
    for (i = 0; i <= b - a; i += 2)
    {
        if (!chkC(segment, i))
            cnt++;
    }
    return cnt;
}
/* 
 * Main
 */
int main()
{
    sieve();
    int a, b;
    cout<<"Enter Lower Bound: ";
    cin>>a;
    cout<<"Enter Upper Bound: ";
    cin>>b;
    cout<<"Number of primes between "<<a<<" and "<<b<<":  ";
    cout<<segmented_sieve(a, b)<<endl;
    return 0;
}