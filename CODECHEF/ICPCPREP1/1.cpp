#include <bits/stdc++.h>
using namespace std;

int max1(std::vector<int> b,std::vector<int> &check)
{
	int max = 0, max_index,i,temp=0;
	for(i=0;i<b.size();i++)
	{
		if(check[i]==0)
		{
			if(b[i]>max)
			{
				max_index = i;
				max = b[i];
				temp = 1;
			}
		}
	}
	if(temp==0)
		return -1;
	check[max_index] = 1;
	return max_index;
}
int main()
{
	int n,m,i,sum=0;
	cin>>n>>m;
	vector<int> a(n,0),b(n,0),c(n,0),check(n,0);
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>c[i]>>b[i];
		sum += a[i];
	}
	// b.sort();
	int time_ = 0;
	m = m*n;
	while(sum<m)
	{
		i = max1(b,check);
		if(i==-1)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		// cout<<"check "<<i<<" "<<sum<<endl;
		check[i]=1;
		int temp = (c[i]-a[i])/b[i];
		if(sum+temp*b[i]<m)
		{
			time_ += temp;
			sum += temp*b[i];
		}
		else
		{
			time_ += (m-sum)/b[i];
			if((m-sum)%b[i]!=0)
				time_ += 1;
			break;
		}
	}
	cout<<time_<<endl;
}