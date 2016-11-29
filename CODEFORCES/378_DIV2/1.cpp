/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <string>
#define MOD 1000000007
#define ll long long int
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<"\n"
#define max1(a,b,c) (max(max(a,b),c))
#define min1(a,b,c) (min(min(a,b),c))
#define mkp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define scan(a); int a; cin>>a 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define init_temp int i,j,k 
using namespace std;

int main()
{
	BOOST;
	init_temp;
	string s;
	cin>>s;
	int len = s.length();
	int last = -1,mini = 0;
	for(i=0;i<len;i++)
	{
		if(s[i] == 'A'||s[i] == 'E'||s[i] == 'I'||s[i] == 'O'||s[i] == 'U'||s[i]=='Y')
		{
			mini = max(mini,i-last);
			last = i;
		}
	}
	mini = max(mini,len-last);
	cout<<mini<<endl;
}