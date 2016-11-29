/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;

int main()
{
	BOOST;
	init_temp;
	cint(t);
	int primes[168] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};

	while(t--)
	{
		cint(n);
		int a[n];
		for(i=0; i<n; i++)
			cin>>a[i];
		ll sum = 0;
		for(j=0;j<168;j++)
		{
			ll even = 0, odd = 0;
			for(i=0;i<n;i++)
			{
				ll count = 0;
				while(a[i]%primes[j] == 0)
				{
					a[i] = a[i]/primes[j];
					count++;
				}
				if(count%2==0)
					even++;
				else odd++;
			}
			sum += min(even,odd);
		}
		map<int,int> big;
		map<int,int>::iterator it;
		for(i=0;i<n;i++)
		{
			if(a[i]>1)
			{
				it = big.find(a[i]);
				if(it==big.end())
					big[a[i]] = 1;
				else
					big[a[i]] ++;
			}
		}
		for (std::map<int,int>::iterator it=big.begin(); it!=big.end(); ++it)
    		sum += min(it->second,n-it->second);
    	out(sum);
	}
}