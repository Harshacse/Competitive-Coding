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
#define init_temp int i,j,k 
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
	cint(n);
	
	ll a[n],sum = 0;
	loop(i,0,n)
	{
		cin>>a[i];
		sum += a[i];
	}
	
	cint(m);
	ll b[m],sum1 = 0;
	loop(i,0,m)
	{
		cin>>b[i];
		sum1 += b[i];
	}

	if(sum!=sum1)
	{
		cout<<"NO\n";
		return 0;
	}

	j = 0;
	for(i=0;i<m;i++)
	{
		if(j==n)
		{
			cout<<"NO\n";
			return 0;
		}
		if(b[i]<a[j])
		{
			cout<<"NO\n";
			return 0;
		}
		else if(b[i]==a[j])
			j++;
		else
		{
			// ll temp = 0,equal,check;
			ll temp = a[j],equal = a[j],check = 1;
			for(k=j+1;k<n;k++)
			{
				if(a[k]!=equal)
					check = 0;
				temp += a[k];
				if(temp == b[i])
					break;
				if(temp > b[i])
				{
					cout<<"NO\n";
					return 0;
				}
				if(k==n)
				{
					cout<<"NO\n";
					return 0;	
				}
			}
			if(check)
			{
				cout<<"NO\n";
				return 0;
			}
			j = k+1;
		}	
	}

	if(j!=n)
	{
		cout<<"NO"<<j<<"\n";
		return 0;
	}

	cout<<"YES\n";
	j = 0;
	for(i=0;i<m;i++)
	{
		if(b[i]==a[j])
			j++;
		else
		{
			ll temp,maxi,ind = j;
			temp = maxi = a[j];
			for(k=j+1;k<n;k++)
			{
				if(maxi<a[k])
				{
					maxi = a[k];
					ind = k;
				}
				temp += a[k];
				if(temp == b[i])
					break;
			}
			if(ind!=i || a[ind]!=a[ind+1])
			{
				int te = ind-j+i, tr = k-ind;
				while(te > i)
				{
					cout<<te+1<<" L\n";
					te--;
				}
				while(tr--)
					cout<<i+1<<" R\n";
				j = k+1;
			}
			else
			{
				int x = ind;
				while(a[x] == a[x+1])
					x++;
				ind = x;
				int te, tr = k-ind;
				while(tr--)
					cout<<i+ind+1<<" R\n";
				te = i+ind;
				while(te > i)
				{
					cout<<te+1<<" L\n";
					te--;
				}
				j = k+1;	
			}
		}	
	}
}