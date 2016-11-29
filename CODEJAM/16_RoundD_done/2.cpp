
#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int caseno = 1;
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		double num = (n-m), denom = (n+m);
		double ans = (double)num/(double)denom;
		printf("Case #%d: %.10f\n",caseno,ans);
		caseno++;
	}	
}