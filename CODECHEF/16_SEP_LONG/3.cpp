#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#define cint(a) int a;cin>>a;
int main()
{
	cint(t);
	int j;
	while(t--)
	{
		cint(n);
		int chef,max = 0,index;
		for(int i=0;i<n;i++)
		{
			vector<int> count(6,0);
			cint(x);
			for(j=0;j<x;j++)
			{
				cint(temp);
				count[temp-1] += 1;
			}
			std::sort(count.begin(),count.end());
			int temp1 = 0,sum = x;
			int cost[3] = {4,2,1};
			for(j=0;j<3;j++)
			{
				count[j] -= temp1;
				sum += count[j]*cost[j];
				temp1 += count[j];
			}
			if(i==0)
				chef = sum;
			else if(sum>max)
			{
				max = sum;
				index = i+1;
			}
			cout<<sum<<endl;
		}
		if(chef < max)
			cout<<index<<'\n';
		else if(chef == max)
			cout<<"tie\n";
		else
			cout<<"chef\n";
	}	
}