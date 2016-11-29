#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,v;
		scanf("%d %d",&s,&v);
		double sf = (double)s,vf = (double)v;
		double ans = (2.0*s)/(3.0*v);
		printf("%.10f\n",ans);
	}
}