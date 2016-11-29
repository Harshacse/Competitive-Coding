#include<stdio.h>
#include<stdlib.h>
int main()
{
  int t,n,i,*a,*b,count,j;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      scanf("%d",&n);
      a= (int*)malloc(n*sizeof(int));
      b= (int*)malloc(n*sizeof(int));
      for(j=0;j<n;j++)
	{
	  scanf("%d",&a[j]);
	}
      for(j=0;j<n;j++)
	{
	  scanf("%d",&b[j]);
	}
      count =0;
      if(a[0]>=b[0])
	count++;
      for(j=1;j<n;j++)
	{
	  if(a[j]-a[j-1]>=b[j])
	    count++;
	}
      printf("%d\n",count);
    }
}
