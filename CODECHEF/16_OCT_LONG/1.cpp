#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,c;
		cin>>n>>m>>c;
		int i,sum=0;
		for(i=1;i<=n;i++)
		{
			if(c%i==0)
			{
				if(m>=c/i)
					sum++;
			}
		}
		cout<<sum<<'\n';
	}
}