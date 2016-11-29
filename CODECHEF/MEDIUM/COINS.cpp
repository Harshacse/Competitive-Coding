#include <stdio.h> 
using namespace std;
#include <vector>
#define ll int
#define MAX 100000

 
ll fun(std::vector<ll> values,ll n)
{
	if(n==0)
		return 0;
	if(n<MAX/10)
		return values[n];
	else if(n<MAX)
	{
		values[n] = (fun(values,n/2)+fun(values,n/3)+fun(values,n/4));
		return values[n]; 
	}
	else
		return (fun(values,n/2)+fun(values,n/3)+fun(values,n/4));
}
int main()
{
	ll n;
	std::vector<ll> values (MAX);
	for(int i=0;i<12;i++)
		values[i] = i;
	values[12] = 13;
	for(int i=13;i<MAX/10;i++)
	{
		values[i] = values[i/2]+values[i/3]+values[i/4];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",fun(values,n));
	}
}