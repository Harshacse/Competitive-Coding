#include <iostream> 
using namespace std;
#include <vector>

int main()
{
	int t,n,a[10],i,j,jmax,max;
	cin>>t;
	while(t--)
	{
		cin>>n;
		max = 0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>max)
				max = a[i];
		}
		int data[max];
		jmax =0;
		for(i=0;i<n;i++)
		{
			j = 2;
			data[0]=data[1]=0;
			while(a[i]>1)
			{
				if(i==0)
					data[j]=0;
				while(a[i]%j!=0)
				{
					a[i]/=j;
					data[j]+=1;
				}
				j+=1;
			}
			if(jmax<j)
				jmax = j;
		}
		int product = 1;
		for(i=0;i<jmax;i++)
			product *= (data[i]+1);
		cout<<product<<endl;
	}
}
