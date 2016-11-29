/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000000000000007
#define ll long long int
#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
using namespace std;

int main()
{
	ll b,d,s,i,j;
	cin>>b>>d>>s;
	ll bf[3],data[3];
	data[0]=b;
	data[1]=d;
	data[2]=s;
	ll mini = MOD,x,num;

	x = max(b,d);
	x = max(x,s);
	num = 3*x - (b+d+s);
	if(num>=0)
		mini = min(num,MOD);

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j!=i)
				bf[j] = data[j]+1;
		}
		bf[i] = data[i];
		x= max(bf[0],bf[1]);
		x = max(x,bf[2]);
		num = 3*x- (bf[0]+bf[1]+bf[2]);
		if(num>=0)
			mini = min(mini,num);
		// cout<<mini<<endl;
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j!=i)
				bf[j] = data[j];
		}
		bf[i] = data[i]+1;
		x= max(bf[0],bf[1]);
		x = max(x,bf[2]);
		num = 3*x- (bf[0]+bf[1]+bf[2]);
		if(num>=0)
			mini = min(num,mini);
		// cout<<mini<<endl;
	}


	cout<<mini<<endl;
}
