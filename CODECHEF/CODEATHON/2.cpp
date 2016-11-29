#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#define cint(a) int a; cin>>a;

int main()
{
	cint(n);
	cint(k);
	std::vector<long long int> a(n+1,0);
	std::vector<long long int> b(n+1,0);
	long long int product = 1;
	int i,j;
	for(i=0;i<k;i++)
	{
		b[i] = product;
		product *= 2;
		a[i] = 0;
	}
	b[k] = product - 1;
	a[k] = 1;
	for(i=k+1;i<=n;i++)
	{
		a[i] = 0;
		product = 1;
		for(j=i-k+1;j>=2;j--)
		{
			a[i] += b[j-2]*product;
			product *= 2;
		}
		a[i] +=  product;
		b[i] = pow(2,i)-a[i];
	}
	long long int res = a[n],den = pow(2,n);
	while(res%2==0)
	{
		res /= 2;
		den/=2;
	}
	cout<<res<<"/"<<den<<'\n';
}