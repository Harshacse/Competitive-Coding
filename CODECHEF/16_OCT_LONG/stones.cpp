#include <bits/stdc++.h>
using namespace std;
#define RANGE 77
#define MAX 1000000007

void countSort(int arr[],int n)
{
    int output[n];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

int calculate(int *a,int ind,int num,int n,int sum,int m,int *temp)
{
	int i,min_ = MAX;
	for(i=num;i<(m/(n-ind+1))+1&&sum-i>=0;i++)
	{
		temp[ind] = i;
		min_ = min(calculate(a,ind+1,i,n,),min_);
	}
	return min_
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,i,j;
		cin>>n>>m;
		int count[n+1][m+1],a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		countSort(a,n);
		for(i=0;i<=m;i++)
			count[n][i]=0;
		for(i=n-1;i>=0;i--)
		{
			for(j=0;)
		}
	}
}