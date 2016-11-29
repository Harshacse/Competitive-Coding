#include <bits/stdc++.h>
#include<stdio.h>

float find(int n,int m)
{
	printf("%d %d\n",n,m );
	if(n==0||m==0)
		return 0.000;
	float ans,ans1;
	int temp = (m>n)?(m%n):(n%m);
	ans = (float)temp * (float)temp;
	if(n>m)
		ans1 = (n>m)?find(n-temp,m+temp):;
	else
		ans1 = find(n+temp,m-temp);
	ans = ans + (ans1)/2.00;
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		printf("%.6f",find(n,m));
	}
}