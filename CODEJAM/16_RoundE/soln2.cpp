#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define LL long long
LL n;

bool pend(int x)
{
	LL tmp=n;
	while (tmp)
	{
		if (tmp%x!=1)return false;
		tmp/=x;
	}
	return true;
}

void work()
{
	int i,minN=(int)min(n,100000LL);
	for (i=2;i<=minN;i++)
		if (pend(i))
		{
			cout<<i<<endl;
			return;
		}
	int x=(int)pow(n,1/3.0);
	if (pend(x))
	{
		cout<<x<<endl;
		return;
	}
	x=(int)pow(n,0.5);
	if (pend(x))
	{
		cout<<x<<endl;
		return;
	}
	cout<<n-1<<endl;
}

int main()
{
	int i,T;
	cin>>T;
	for (i=1;i<=T;i++)
	{
		cin>>n;
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
