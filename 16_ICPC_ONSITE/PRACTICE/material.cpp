/*
************* Number Theory ***************
*/
TOPIC 1:
//Segmented Sieve:
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
//sp[x] gives the least prime factor of x. It can be used for the prime factor decompositon of x

TOPIC 2:
NUMBER OF PRIMES BETWEEN a and b:
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

/* 
 * Sieve of Atkins
 */
void sieve_atkins(ll int n)
{
    vector<bool> is_prime(n + 1);
    is_prime[2] = true;
    is_prime[3] = true;
    for (ll int i = 5; i <= n; i++)
        is_prime[i] = false;
    ll int lim = ceil(sqrt(n));
    for (ll int x = 1; x <= lim; x++)
    {
        for (ll int y = 1; y <= lim; y++)
        {
            ll int num = (4 * x * x + y * y);
            if (num <= n && (num % 12 == 1 || num % 12 == 5))
                is_prime[num] = true;
            num = (3 * x * x + y * y);
            if (num <= n && (num % 12 == 7))
                is_prime[num] = true;
            if (x > y)
            {
                num = (3 * x * x - y * y);
                if (num <= n && (num % 12 == 11))
                    is_prime[num] = true;
            }
        }
    }
    for (ll int i = 5; i <= lim; i++)
    {
        if (is_prime[i])
        {
            for (ll int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
 
    for (ll int i = 2; i <= n; i++)
    {
         if (is_prime[i])
             cout<<i<<"\t";
    }
}
int main()
{
    ll int n;
    n = 300;
    cout<<"Following are the prime numbers below "<<n<<endl;
    sieve_atkins(n);
    cout<<endl;
    return 0;
}

int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(int d, int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    int x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    // Iterate given nber of 'k' times
    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;
 
    return true;
}
 
// Driver program
int main()
{
    int k = 4;  
    cout << "All primes smaller than 100: \n";
    for (int n = 1; n < 100; n++)
       if (isPrime(n, k))
          cout << n << " ";
 
    return 0;
}

/*
nCr mod m code
*/
vector<ll> fac(5005,1);
vector<ll> inverse(5005,1);

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%MOD;
	ll small = power(a,b/2);
	ll temp = (small*small)%MOD;
	if(b%2==0)
		return temp;
	else
	{
		ll temp1 = (a*temp)%MOD;
		return temp1;
	}
}

ll C(ll n,ll i)
{
	if(n==i)
		return 1;
	if(i==0)
		return 1;
	ll temp = inverse[i], temp1 = inverse[n-i];
	ll result = (temp*temp1)%MOD;
	result = (result*fac[n])%MOD;
	return result;
}

int main()
{
	BOOST;
	ll_init_temp;
	for(i=1;i<=5000;i++)
		fac[i] = (i*fac[i-1])%MOD;
	for(i=0;i<=5000;i++)
		inverse[i] = power(fac[i],MOD-2);
	out(C(5,2));
}


/*
	LUCAS THEOREM: Computes (nCr%p)
	Time Complexity: Time complexity of this solution is O(p2 * Logp n). 
	There are O(Logp n) digits in base p representation of n. 
	Each of these digits is smaller than p, therefore, computations for 
	individual digits take O(p2). 
*/
using namespace std;
 
// Returns nCr % p.  In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
int nCrModpDP(int n, int r, int p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
 
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
 
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
 
// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModpLucas(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;
 
   // Compute last digits of n and r in base p
   int ni = n%p, ri = r%p;
 
   // Compute result for last digits computed above, and
   // for remaining digits.  Multiply the two results and
   // compute the result of multiplication in modulo p.
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}
 
// Driver program
int main()
{
    int n = 1000, r = 900, p = 13;
    cout << "Value of nCr % p is " << nCrModpLucas(n, r, p);
    return 0;
}

