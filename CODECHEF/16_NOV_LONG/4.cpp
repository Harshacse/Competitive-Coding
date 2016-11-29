/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <vector>
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
#define out(a) cout<<a<<"\n"
using namespace std;


vector <int> indices;
class KMP
{
public:
    KMP(string txt, string pat)
    {
        KMPSearch(txt,pat);
    }
   
    void KMPSearch(string txt, string pat)
    {
        int M = pat.length();
        int N = txt.length();
        int lps[M];
        computeLPSArray(pat, M, lps);
     
        int i = 0;  
        int j  = 0;  
        while (i < N)
        {
            if (pat[j] == txt[i])
            {
                j++;
                i++;
            }
     
            if (j == M)
            {
                indices.push_back(i-j);
                j = lps[j-1];
            }
     
            else if (i < N && pat[j] != txt[i])
            {
                if (j != 0)
                    j = lps[j-1];
                else
                    i = i+1;
            }
        }
    }
     
    void computeLPSArray(string pat, int M, int *lps)
    {
        int len = 0;
     
        lps[0] = 0; 
        int i = 1;
        while (i < M)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else 
            {
                if (len != 0)
                {
                    len = lps[len-1];
                }
                else 
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }    
};
 
int main()
{
    clock_t t1,t2;
    t1=clock();
    float diff,seconds;
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		string S,F;
		indices.clear();
		cin>>S;
		cin>>F;
        int m = S.length(),n = F.length();
        if(m<n)
        {
            cout<<"0\n";
            continue;
        }
		KMP temp(S,F);
        vector<int> next(m+7,0);
        int sz = indices.size();
		int last = 0;
		if(sz <= 1)
		{
			cout<<sz;
            nl;
			continue;
		}

		for(i=0;i<sz;i++)
		{
			for(j=last;j<indices[i];j++)
			{
				next[j] = indices[i];
			}
			last = indices[i];
		}
		for(i=last;i<=m;i++)
			next[i] = m;
		std::vector<ll> count(m+7,0);
		std::vector<ll> total(m+7,1);
		total[m] = 1;
		count[m] = 0;
		total[indices[sz-1]] = 2;
		count[indices[sz-1]] = 1;
		for(i=sz-2;i>=0;i--)
		{
			j = indices[i];
			count[j] = total[next[j+n-1]];
            ll sum = count[j]%MOD;
            sum = (sum+total[indices[i+1]])%MOD;
			total[indices[i]] = sum%MOD;
		}
		ll x = total[indices[0]]-1;
		if(x<0)
			x+=MOD;
		out(x);
	}
    t2=clock();
    diff = ((float)t2-(float)t1);
    seconds = diff / CLOCKS_PER_SEC;
    // cout<<"Run time:"<<seconds<<endl;
}