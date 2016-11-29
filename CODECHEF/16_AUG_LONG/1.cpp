#include<iostream>
using namespace std;
int main()
{
	int n,m,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n%2 ==0 || m%2 == 0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}