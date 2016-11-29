#include<stdio.h>
#include<stdlib.h>
int main()
{
   int t,n,i,j,k,max1,max2,max,*a;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      scanf("%d",&n);
      a= (int*)malloc(n*sizeof(int));
      for(j=0;j<n;j++)
         scanf("%d",&a[j]);
     max=0;
     for(k=0;k<n;k++)
     {
        if(a[k]>0)
          continue;
        max1 = max2 = 0;
        for(j=0;j<n;j++)
        {
           if(j==k)
              continue;
           max2 = max2 + a[j];
           if(max2<0)
           {
              max2=0;
           }
           if(max1<max2)
           max1=max2;
        }
        if(max<max1)
           max=max1;
     }
     if(max==0)
     {
         max= a[0];
         for(j=1;j<n;j++)
         {
             if(a[j]>max)
             max=a[j];
         }
     }
      printf("%d\n",max);
    }

}
