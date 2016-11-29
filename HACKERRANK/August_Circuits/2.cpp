#include <iostream>
using namespace std;
#define cint(a) int a; cin>>a;
#define cint2(a,b) int a,b; cin>>a>>b;

int gcd(int a, int b)
{
	if(a%b == 0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	cint(t);
	while(t--)
	{
		cint2(n,m);
		int d = gcd(9*m,m+8*n);
		int num = 9*m/d, denom = (m+8*n)/d;
		cout<<num<<"/"<< denom<<"\n";
	}
}