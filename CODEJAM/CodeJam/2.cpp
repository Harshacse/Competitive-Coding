#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
long long int calculate(long long int i,long long int a,long long int k)
{
	if(a==0)
		return 1;
	if(a==1)
		return i%k;
	long long int temp,ans;
	if(a%2==1)
	{
		 temp = calculate(i,a/2,k);
		 ans = (temp*temp)%k;
		 ans *= i;
		 ans = ans%k;
		 return ans;
	}
	else
	{
		 temp = calculate(i,a/2,k);
		 ans = (temp*temp)%k;
		 return ans;
	}
}

int main()
{
	long long int t,a,b,n,k,i,j,cas=1;
	long long int result,sub,ansa,ansb,temp1,temp2,factor;
	cin>>t;
	while(t--)
	{
		result = sub = 0;
		cin>>a>>b>>n>>k;
		vector<long> rema(k,0),remb(k,0);
		rema[1] = 1;
		remb[1] = 1;
		if(k==2)
			sub +=1;
		for(i=2;i<=n;i++)
		{
			ansa =  calculate(i,a,k);
			ansb  = calculate(i,b,k);
			if(ansa+ansb==k)
				sub+=1;
			rema[ansa]+=1;
			remb[ansb]+=1;
		}
		for(i=1;i<k;i++)
		{
			result = (result +(long long int)rema[i]*(long long int)remb[k-i])%MOD;
		}
		result = (result + rema[0]*remb[0])%MOD;
		result-=sub;
		cout<<"Case #"<<cas<<": "<<result%MOD<<" "<<sub<<'\n';
		cas+=1;
	}	
}