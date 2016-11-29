/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;


ll power(ll count)
{
	if(count == 1)
		return 2;
	if(count == 0)
		return 1;
	ll x = power(count/2);
	if(count%2 == 0)
		return (x*x)%MOD;
	else
		return (x*x*2)%MOD;
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    ll t;cin>>t;

    while(t--)
    {

    	string a,b;
    	cin>>a>>b;
    	
    	ll n = a.size();
    	vector<ll> v(n,0);
    	ll i,count;
    	for(i=0;i<n;i++)
    		v[i] = (a[i] - '1') + (b[i] - '1');

    	bool check = true;
    	i = 0;
    	count = 0;
    	while(i<n && check)
    	{
    		// cout <<i<<endl;
    		if(i+1 == n)
    		{
    			count++;
    			break;
    		}
    		if(v[i] == 0)
    		{
    			count++;
    			i++;
    		}
    		else if(v[i] == 2) 
    		{
    			if(i+3 >= n)
    				check = false;
    			else if(v[i+1] == 2 && v[i+2] == 0)
    			{
    				count += 3;
    				i+=3;
    			}
    			else
    				check = false;
    		}
    		else
    		{
    			if(v[i+1] == 2)
    			{
    				count += 1;
    				if(i+4 >= n)
    					check = false;
    				else if(v[i+2] != 1)
    					check = false;
    				else
    				{
						if(v[i+3] == 0)
							count += 1;
						i+=3;
    				} 
    			}
    			else if(v[i+1] == 1)
    			{
    				if(i+3 >= n)
    					check = false;
    				else if(v[i+2] == 2)
    					check = false;
    				else if(v[i+2] == 0)
    				{
    					count += 2;
    					i += 3;
    				}
    				else
    					i+=2;
    			}
    			else
    				check = false;
    		}
    	}
		
		if(check)
			cout<<power(count)<<endl;
		else
			cout<<"0\n";    
    }
}