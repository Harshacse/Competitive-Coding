#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n+1];
	a[1]=1; a[0]=1;
	for(i=2;i<=n;i++)
	{
		a[i] = 0;
		for(j=1;j<=i;j++)
		{
			a[i] += a[j-1]*a[i-j];
		}
	}
	printf("%d",a[n]);
}