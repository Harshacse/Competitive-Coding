#include<iostream>
#include<math>
using namespace std;
#define ll long long int
int answer(int n,int k)
{
	double temp,temp1;
	ll tl = 1,tl1;
	temp1 = (double)k/100.0;
	while(1)
	{
		temp = math.sqrt(2*tl*n - tl*tl);
		tl1 = (int)temp;
		temp = n- math.sqrt((n-tl)*(n-tl)+tl1*tl1);
		if(temp>temp1)

	}
}
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
			temp = math.sqrt(2*tl*n - tl*tl);
			tl1 = (int)temp;
			temp = n- math.sqrt((n-tl)*(n-tl)+tl1*tl1);
			if(temp>temp1)
			{
				check=1;
				break;
			}	
			tl++;	
		}
		if(check)
			cout<<n-tl<<" "<<tl1;
		else
			cout<<"-1"<<endl;
	}	
}