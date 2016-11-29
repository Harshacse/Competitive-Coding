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

ll m,l;
ll powers[10010];

ll conquer(vector<ll> &data,ll left,ll right,vector<int> &v,ll *total)
{
	int i,j;
	if(left==right)
	{
		v[data[left]%m] = 1;
		*total = data[left]%m;
		if(data[left]%m==l)
			return 1;
		else 
			return 0;
	}

	ll mid = (left+right)/2;
	vector < vector <int> > v1(m,vector<int>(0) ),v2(m,vector<int>(0) );
	
	ll tot1,tot2,tot;
	ll sum = conquer(data,left,mid,v1,&tot1);
	sum = sum + conquer(data,mid+1,right,v2,&tot2);
	memset(v,0,sizeof v);
	tot = tot2;
	for(i=0;i<m;i++)
	{
		for(j=0;j<v1[i].size();j++)
		{
			ll temp = v1[i][j],temp1,temp2;
			temp1 = (i*powers[mid-temp+1])%m;
			ll x= l-temp1;
			if(x<0)
				x+=m;
			temp2 = tot-x;
			if(temp2<0)
				temp2 += m;
			sum += v2[m].size();
		}
	}

	v[data[right]%m].pb(right);
	ll temp = data[right]%m;
	for(i=right-1;i>=left;i--)
	{
		temp = (temp+ powers[right-i]*data[i])%m;
		v[temp].pb(i);
	}
	*total = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	powers[0] = 1;
    string s;
    cin>>s;
    ll q,i,j;
    cin>>q;
    int n = s.size();
    std::vector<int> v(n,0);
	for(i=0;i<n;i++)
		v[i] = s[i] - '0';
    while(q--)
    {
    	cin>>m>>l;
    	ll total;
    	for(i=1;i<=n/2;i++)
    		powers[i] = (powers[i-1]*10)%m; 
    	vector < vector <int> > v1(500,vector<int>(0));
    	cout<<conquer(v,0,n-1,v1,&total);
    }
}