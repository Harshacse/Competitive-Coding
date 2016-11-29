#include<iostream>
#include<math.h>
using namespace std;
#define ll long long int

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		double temp;
		double temp1;
		ll tl = 1,tl1;
		temp1 = (double)k/100.0;
		int check = 0;
		while(tl<n/2)
		{
			temp = sqrt(2*tl*n - tl*tl);
			tl1 = (int)temp;
			temp = n- sqrt((n-tl)*(n-tl)+tl1*tl1);
			// cout<<tl<<" "<<tl1<<" "<<temp<<endl;
			if(temp<temp1)
			{
				check=1;
				break;
			}	
			tl++;	
		}
		if(check)
			cout<<n-tl<<" "<<tl1<<endl;
		else
			cout<<"-1"<<endl;
	}	
}