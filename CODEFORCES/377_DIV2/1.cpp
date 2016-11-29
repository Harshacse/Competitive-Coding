/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

int main()
{
	int n,r,x,i;
	cin>>n>>r;
	int a = n;
	i =1;
	while(1)
	{
		if(((a*i)%10==0)||(a*i-r)%10 == 0 && (a*i-r)>=0)
			break;
		i++;
	}
	cout<<i<<endl;
}