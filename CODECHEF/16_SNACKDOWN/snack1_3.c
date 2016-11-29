#include<stdio.h>
#include<stdlib.h>
int gcd(int c,int d)
{
	if(c>d)
	{
		if(c%d==0)
			return d;
		else
			return gcd(d,c%d);
	}
	else
	{
		if(d%c==0)
			return c;
		else
			return gcd(c,d%c);
	}
}
int main()
{
	int t,n,a,b,c,d,i,temp,result;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		temp = gcd(c,d);
		if(a>b)
		{
			result = ((a-b)%temp > temp-(a-b)%temp)?temp-(a-b)%temp : (a-b)%temp;
		}
		else
		{
			result = ((b-a)%temp > temp-(b-a)%temp)?temp-(b-a)%temp : (b-a)%temp;
		}
		printf("%d\n",result);
	}
}