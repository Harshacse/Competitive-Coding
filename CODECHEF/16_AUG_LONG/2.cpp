#include<iostream>
using namespace std;
int main()
{
	int t,n,temp,i,j,sum,temp1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		i = 0;
		int b[n],check[n];
		while(i<n)
		{
			cin >> temp;
			b[i] = (temp+i+1)%n;
			check[i] = 0;
			i++;
		}
		// cout<<"b "<<b[0]<<b[1]<<b[2]<<b[3]<<endl;
		sum = 0;
		for(i=0;i<n;i++)
		{
			if(check[i]==0)
			{
				j = i;
				while(check[j]==0)
				{
					check[j]+=1;
					j=b[j];
				}
				temp1 = j;
				temp = 1;
				if(check[j]==1)
				{
					check[j]+=1;
					while(b[j]!=temp1)
					{
						j=b[j];
						if(check[j]!=1)
						{
							temp=0;
							break;
						}
						check[j]+=1;
						temp += 1;
					}
					sum += temp;
				}
			}
		}
		cout<<sum<<endl;
	}
}