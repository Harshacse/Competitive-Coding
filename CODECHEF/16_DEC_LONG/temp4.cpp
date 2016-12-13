/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/
 
#include <bits/stdc++.h>
#include <cmath>
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
#define init_temp int i,j
#define ll_init_temp ll i,j
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n"
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;
 
int indices[100005];
 
/*
	NOTE : HEAP SORT CODE BORROWED FROM INTERNET. 	
	REFER TO LINK http://www.sanfoundry.com/cpp-program-implement-heap-sort/
*/
 
void max_heapify(int *a, int i, int n)
{
    int j, temp,tempi;
    temp = a[i];
    tempi = indices[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] < a[j])
            j = j+1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            indices[j/2] = indices[j];
            j = 2*j;
        }
    }
    indices[j/2] = tempi;
    a[j/2] = temp;
    return;
}
 
void heapsort(int a[], int n)
{
    int i, temp, tempi;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        tempi = indices[i];
        a[i] = a[1];
        indices[i] = indices[1];
        a[1] = temp;
        indices[1] = tempi;
        max_heapify(a, 1, i - 1);
    }
}
 
void build_maxheap(int a[], int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}
 
int bs(ll sum[],ll x,int start,int end,int n)
{
	int mid = (start+end)/2;
	if(mid == n || mid == 1)
		return mid;
	if(sum[mid]<x && sum[mid+1]>=x)
		return (mid+1);
	else if(sum[mid]<x)
		bs(sum,x,mid,end,n);
	else if(sum[mid]>=x && sum[mid-1]<x)
		return mid;
	else 
		bs(sum,x,start,mid,n);
}
 
int main()
{
	init_temp;
	cint(t);
	while(t--)
	{
		cint2(n,m);
		int a[n+1],b[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i] = a[i];
			indices[i] = i;		
		}
		build_maxheap(b,n);
		heapsort(b,n);
		ll sum[n+1];
		sum[0] = 0;
		for(i=1;i<=n;i++)
		{
			sum[i] = sum[i-1] + (n-indices[i]+1);
			out(indices[i]);
		}
		// out(sum[n]);
		while(m--)
		{
			ll x;
			cin>>x;
			int temp = bs(sum,x,1,n,n);
			// out(temp);
			out(b[temp]);
		}	
	}
}