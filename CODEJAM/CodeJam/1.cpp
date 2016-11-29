#include<iostream>
using namespace std;
int main()
{
	int i,t,L,R,temp;
	cin>>t;
	long answer;
	i=1;
	while(t--)
	{
		cin>>L>>R;
		temp = min(L,R);
		answer = (long)(temp)*(long)(temp+1);
		answer/=2;
		cout<<"Case #"<<i<<": "<<answer<<'\n';
		i++;
	}
}