/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <string>
#define MOD 1000000007
#define ll long long int
#define min(a,b) (a>b)?b:a
#define max(a,b) (a>b)?a:b
#define nl cout<<"\n"
#define max1(a,b,c) max(max(a,b),c)
#define min1(a,b,c) min(min(a,b),c)
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
	int t,caseno = 0;
	cin>>t;
	while(t--)
	{
		caseno++;
		int n,l;
		cin>>n>>l;
		string input[n],output[n];
		for(i=0;i<n;i++)
			cin>>input[i];
		for(i=0;i<n;i++)
			cin>>output[i];
		ll mini = MOD;
		for(i=0;i<n;i++)
		{
			vector <int> flip(n,0);
			ll sum = 0;
			for(j=0;j<l;j++)
			{
				if(input[0][j]!=output[i][j])
				{
					flip[j]=1;
					sum += 1;
				}
			}
	
			vector <int> check(n,0);
			check[i] = 1;
			for(j=1;j<n;j++)
			{
				char temp[l+1];
				for(k=0;k<l;k++)
				{
					if(flip[k] == 1)				
						temp[k] = '0'+(int)('1'-input[j][k]);
					else
						temp[k] = input[j][k];
				}
			
				for(k=0;k<n;k++)
				{
					if(check[k] == 1)
						continue;
					int x,control = 0;
					for(x=0;x<l;x++)
					{
						if(output[k][x]!=temp[x])
						{
							control = -1;
							break;
						}
					}
					if(control == -1)
						continue;
					else
					{
						check[k] = 1;
						break;
					}	
				}

				if(k==n)
				{
					sum = MOD;
					break;
				}
			}
			if(j==n)
				mini = min(mini,sum);
		}
		
		if(mini==MOD) cout<<"NOT POSSIBLE\n";
		else cout<<"Case #"<<caseno<<": "<<mini<<"\n";
	}
}