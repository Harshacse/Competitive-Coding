#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,N,K,i,j,k;
	int *lis;
	long long maxi,mini,**maximum,**minimum;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&N);
		scanf("%d",&K);
		lis = (int*)malloc(N*sizeof(int));
		for(j=0;j<N;j++)
		{
			scanf("%d",&lis[j]);
		}
		maximum = (long long**)malloc(K*sizeof(long long*));
		minimum = (long long**)malloc(K*sizeof(long long*));
		for(j=0;j<N;j++)
		{
			maximum[j] = (long long*)malloc(N*sizeof(long long));
			minimum[j] = (long long*)malloc(N*sizeof(long long));
		}
		maxi = lis[0];
		for(j=0;j<N;j++)
		{
			if(maxi < lis[j])
				maxi = lis[j];
			maximum[0][j] = maxi;
		}
		mini = lis[0];
		for(j=0;j<N;j++)
		{
			if(mini > lis[j])
				mini = lis[j];
			minimum[0][j] = mini;
		}
		for(j=1;j<K;j++)
		{
			maxi = maximum[j-1][j-1]*lis[j];
			for(k=0;k<j;k++)
				maximum[j][k] = 0;
			maximum[j][j]=maxi;
			for(k=j+1;k<N;k++)
			{
				if(maxi < maximum[j-1][k-1]*lis[k])
					maxi = maximum[j-1][k-1]*lis[k];
				if(maxi < minimum[j-1][k-1]*lis[k])
					maxi = minimum[j-1][k-1]*lis[k];
				maximum[j][k]= maxi;
			}

			mini = minimum[j-1][j-1]*lis[j];
			for(k=0;k<j;k++)
				minimum[j][k] = 0;
			minimum[j][j]=mini;
			for(k=j+1;k<N;k++)
			{
				if(mini > maximum[j-1][k-1]*lis[k])
					mini = maximum[j-1][k-1]*lis[k];
				if(mini > minimum[j-1][k-1]*lis[k])
					mini = minimum[j-1][k-1]*lis[k];
				minimum[j][k]= mini;
			}
		}
		if(maximum[K-1][N-1]>=0)
			printf("%lld\n",(maximum[K-1][N-1])%(1000000007));
		else
			printf("%lld\n",1000000007+(maximum[K-1][N-1])%(1000000007));		
	}
}