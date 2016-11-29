/*
Author : segf
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<'\n'
#define max1(a,b,c) max(max(a,b),c)
#define min1(a,b,c) min(min(a,b),c)
#define mkp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,j,k,l;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ones = 0;
		int minusones = 0;
		int num = 0;
		int check = 0;
		int x;
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(x==0)
				continue;
			else if(x==1)
			{
				ones++;
			}
			else if(x == -1)
			{
				minusones++;
			}
			else check++;
		}

		if(check == 0)
		{
			if(minusones>1 && ones==0)
				cout<<"no\n";
			else cout<<"yes\n";
		}
		else if(check == 1)
		{
			if(minusones!=0)
				cout<<"no\n";
			else cout<<"yes\n";
		}
		else if(check > 1)
			cout<<"no\n";
	}
}