/*
Author : Kanakamedala Jayachandra
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <math.h>
#define MOD 1000000007
#define ll long long int
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXInT 2147483647
#define MAXLOnG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp int i,j
#define ll_init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(nULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define MAX 1000005
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n"
#define out2(a,b) cout<<a<<" "<<b<<"\n"
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;

int weigh[100005],cnt[1000005],a[100005],wc[100005],F[1000005];
ll num;
void merge(int left,int mid,int right)
{
    init_temp;
    int p=left,q=mid+1,k=0,c=0;
    for(i=left;i<=right;i++,k++)
    {
        if(p>mid)
            a[k] = weigh[q++];
        else if(q>right)
        {
            a[k] = weigh[p];
            cnt[weigh[p]] += c;
            p++;
        }
        else if(weigh[p] <= weigh[q])
        {
            a[k] = weigh[p];
            cnt[weigh[p]] += c;
            p++;
        }
        else
        {
            a[k] = weigh[q++];
            num += mid-p+1;
            c++;
        }
    }
    for(i=0;i<k;i++)
        weigh[left++] = a[i];
}
void mergeSort(int left,int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        merge(left,mid,right);
    }
}
int main()
{
    init_temp;
    cint(t);
    while(t--)
    {
        num =0 ;
        for(i=0;i<MAX;i++)
            cnt[i] = 0;
        cint(n);
        for(i=0;i<n;i++)
        {
            cin>>weigh[i];
            wc[i] = weigh[i];
        }
        mergeSort(0,n-1);
        ll sum = 0;
        for(i=0;i<n;i++)
        {
            if(i != n-1)
                cout<<cnt[wc[i]]<<" ";
            else
                out(cnt[wc[i]]);
        }
    }
    return 0;
}