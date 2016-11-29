#include <iostream>
using namespace std;
#include <vector>
#define lld long long int 

int main()
{
	long long int t,count=0,n,i,j,k,cas=1,temp;
	lld answer;
	lld m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		lld onecase[5001],factorial[5001],sum;
		vector < vector <long long int> > result(5000, vector<long long int> (5000,0));
		onecase[1] = 1;
		onecase[2] = 1;
		factorial[1] = 1;
		for(i=2;i<=n;i++)
			factorial[i] = (i*factorial[i-1])%m;
		for(i=3;i<=n;i++)
		{
			// cout<<"factorial["<<i<<"] : "<<factorial[i]<<endl;
			onecase[i] = 0;
			sum = 0;
			j = 1;
			for(k=1;k<i;k++)
			{
				temp = factorial[k]-sum;
				if(temp<0)
					temp+=m;
				onecase[i] = (onecase[i] + factorial[i-k]*onecase[k])%m;
				sum = (sum + factorial[k])%m;
			}
			onecase[i] = factorial[i]-onecase[i];
			if(onecase[i]<0)
				onecase[i]+=m;
			// cout<<"onecase["<<i<<"] : "<<onecase[i]<<endl;
		}
		for(i=1;i<=n;i++)
		{
			result[i][i]=1;
			result[i][1]=onecase[i];
			for(j=2;j<=i;j++)
			{
				result[i][j] = 0;
				for(k=1;k<=i-j+1;k++)
					result[i][j] = (result[i][j] + onecase[k]*result[i-k][j-1])%m;
				// cout<<"result["<<i<<j<<"] : "<<result[i][j]<<endl;
			}
		}
		answer = 0;
		for(i=1;i<=n;i++)
			answer = (answer + result[n][i]*i*i)%m;
		cout<<"Case #"<<cas++<<": "<<answer<<'\n';
	}
}
