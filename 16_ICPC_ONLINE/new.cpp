/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define min(a,b) (a>b)?b:a
#define max(a,b) (a>b)?a:b
#define nl cout<<'\n'
#define max1(a,b,c) max(max(a,b),c)
#define min1(a,b,c) min(min(a,b),c)
#define mkp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define scan(a); int a; cin>>a 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j,k 
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s;
    cin>>s;
    ll q,i,j;
    cin>>q;
    int n = s.size();
    std::vector<int> data(n,0);
	for(i=0;i<n;i++)
		data[i] = s[i] - '0';
    while(q--)
    {
    	ll m,l;
    	cin>>m>>l;
    	std::vector<int> v(m,0);
    	v[data[0]%m] = 1;
    	ll sum = 0;
    	if(data[0]%m==l)
    		sum +=1;

    	for(i=1;i<n;i++)
    	{
    		std::vector<int> temp(m,0);
    		temp[data[i]%m] = 1;
    		for(j=0;j<m;j++)
    			temp[(10*j+data[i])%m] += v[j];
    		sum += temp[l];
    		v = temp;
    	}
    	cout<<sum;nl;
    }
}