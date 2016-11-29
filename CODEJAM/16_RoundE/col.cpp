/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp ll i,j,k 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a;nl
using namespace std;

int main()
{
	BOOST;
	init_temp;
	cll(t);
	ll caseno = 1;
	while(t--)
	{
		string s;
		cin>>s;
		ll len = s.length();
		ll cnt = 0;
		for(i=0;i<len;i++)
			if(s[i]=='B')
				cnt++;
		// out(cnt);
		ll m,n;
		cin>>m>>n;
		ll sum = 0;
		ll temp1,temp2;
		if((n+1)/len == m/len)
		{
			for(i=m;i<=n;i++)
			{
				if(s[(i-1)%len]=='B')
					sum++;
			}
			cout<<"Case #"<<caseno<<": "<<sum<<endl;
			caseno++;
			continue;
		}

		if(m%len!=0)
		{
			temp1 = (m/len) + 1;
			ll temp = m%len;
			temp = len-temp;
			for(i=0;i<temp;i++)
			{
				if(s[(m+i-1)%len] == 'B')
					sum++;
			}
		}
		else
			temp1 = m/len;
		if((n+1)%len!=0)
		{
			temp2 = (n+1)/len;
			ll temp = (n+1)%len;
			for(i=0;i<temp;i++)
			{
				if(s[(n-i-1)%len] == 'B')
					sum++;
			}	
		}
		else
			temp2 = (n+1)/len;
		sum += (temp2-temp1)*cnt;
		cout<<"Case #"<<caseno<<": "<<sum<<endl;
		caseno++;
	}
}