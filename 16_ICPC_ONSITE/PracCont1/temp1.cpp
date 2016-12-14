#include <iostream>
using namespace std;
int BIT[10001];
int n=10001;
void add(int pos,int val)
{
	for(;pos<=n;pos+=(pos&-pos))
	{
		BIT[pos]+=val;
	}
}
int get(int pos)
{
	int ans=0;
	for(;pos>0;pos-=(pos&-pos))
	{
		ans+=BIT[pos];
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int inv[n];
	for(int i=n-1;i>=0;i--)
	{
		inv[i]=get(arr[i]);
		add(arr[i],1);
	}
	for(int i=0;i<n;i++)
		cout<<inv[i]<<" ";
}