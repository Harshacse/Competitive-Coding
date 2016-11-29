#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,*a,i,j,check;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		check = 0;
		scanf("%d",&n);
		a = (int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(j=0;j<n-2;j++)
		{
			if(a[j]==a[j+1] && a[j+1]==a[j+2])
				check = 1;
		}
		if(check==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}