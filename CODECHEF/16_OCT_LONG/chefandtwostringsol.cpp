/*
*Author: Keshav Agarwal
*Institution: IIT Kharagpur
*/
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> 
#include <map>
#include <stdio.h>
#include <cmath>
#define MOD 1000000007
#define maxm(cm,dm) ((cm)>(dm)?(cm):(dm))
#define minm(cm,dm) ((cm)<(dm)?(cm):(dm))
#define exc(ae,be,te) (te)=(ae), (ae)=(be), (be)=(te)
#define ll long long int
#define loop(i,a,b) for (int i = (a); i < (b); i++)
#define mpa make_pair
#define pii pair<int,int>
#define rep(i,b) loop(i,0,b)
#define repe(i,b) loop(i,1,b+1)
using namespace std;
 
int fast_pow(long long base, long long n)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2);
    if(n%2==0)
        return ( halfn * halfn ) % MOD;
    else
        return ( ( ( halfn * halfn ) % MOD ) * base ) % MOD;
}
 
bool chk(string s) {
    int n = s.size();
    int i=0;
    while(i < (n-1)) {
        if(s[i] == '1')
            i++;
        else {
            if(i>=n-3)
                return false;
            if(s[i+1] != '2' || s[i+2] != '1')
                return false;
            i+=3;
        }
    }
 
    return true;
}
 
int get(string a, string b, int i) {
    if(i >= a.size()) { 
        if(chk(a)&&chk(b)) {
            //cout<<a<<" "<<b<<endl;
            return 1;
        }
        else
            return 0;
    }
    int ans = 0;
    if(a[i]==b[i]) {
        ans = (2*get(a,b,i+1))%MOD;
        return ans;
    }
    ans = get(a,b,i+1);
    char c = a[i];
    a[i] = b[i];
    b[i] = c;
    ans += get(a,b,i+1);
    return ans%MOD;
}
 
 
 
int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int n;
    string a,b;
    ll ans2,ans;
    int c;
 
    rep(test,t)
    {
        cin >> a >> b;
        n = a.size();
        vector<int> v(n,0);
        if(n == 1) {
            cout<<"2\n";
            continue;
        }
        c = 0;
        rep(i,n-1) {
            v[i] = (a[i] - '1') + (b[i] - '1');
            c += v[i];
        }
        if(c % 2 != 0) {
            cout<<"0\n";
            continue;
        }
        int d = 0;
        c = 0;
        // cout<<a<<" "<<b<<endl;
        rep(i,n-1) {
            // cout<<v[i]<<" "<<d<<" "<<c<<" - ";
            if(v[i] == 0) {
                if(d == -4)
                    c+=3;
                else if(d == -2) {
                    c = 0;
                    break;
                }
                else if(d == 0)
                    c++;
                else if(d % 2 == 0)
                    c+=2;
                else {
                    c = 0;
                    break;
                }
                d = 0;
            }
            else if(v[i] == 1) {
                if(d < 0) {
                    c = 0;
                    break;
                }
                d++;
            }
            else {
                if(i == 0 || (i > 0 && v[i-1] != 2)) {
                    if(d % 2 != 0) {
                        d += 2;
                        c++;
                    }
                    else if(d != 0) {
                        c = 0;
                        break;
                    }
                    else
                        d = -2;
                }
                else if(i > 0) {
                    if(d == -2)
                        d -= 2;
                    else {
                        c = 0;
                        break;
                    }
                }
                // if(d % 2 != 0) {
                //     d = 1;
                //     c++;
                // }
                // else if(d == 0) {
                //     d = -2;
                // }
                // else if(d == -2) {
                //     d -= 2;
                // }
                // else {
                //     c = 0;
                //     break;
                // }
            }
        }
        if(v[n-2] >= 1)
            c=0;
        if(c == 0)
            cout<<"0\n";
        else
            cout<<(2*fast_pow(2,c))%MOD<<"\n";
    }
    return 0;
}
 