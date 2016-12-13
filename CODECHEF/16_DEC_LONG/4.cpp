/*
Author : Ponnada Harsha Vardhan
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
#define out2(a,b) cout<<a<<" "<<b<<"\n"
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

ll bs(ll sum[],ll x,ll start,ll end,int n)
{
	ll mid = (start+end)/2;
	if(start == end)
		return mid;
	if(sum[mid]<x)
	{
		if(sum[mid+1]>=x)
			return (mid+1);
		else
			bs(sum,x,mid,end,n);	
	}	
	else if(sum[mid]>=x)
	{
		if(sum[mid-1]<x)
			return mid;
		else 
			bs(sum,x,start,mid,n);
	} 
}

class SegmentTree
{
    public:
        int *st,*arr;
        int n;
        SegmentTree(int *arr_,int n_)
        {
            n = n_;
            arr = arr_;
            int x = (int)(ceil(log2(n))); 
            int max_size = 2*(int)pow(2, x) - 1; 
            st = new int[max_size]; 
            build(0, n-1, 0);
        }
        // int max(int x, int y) { return (x > y)? x: y; }
        int getMid(int s, int e) {  return s + (e -s)/2; }  
        int query_solve(int ss, int se, int qs, int qe, int index);
        int query(int qs, int qe);
        int build(int ss, int se, int si);
};


int SegmentTree::query_solve(int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return max(query_solve(ss, mid, qs, qe, 2*index+1),query_solve(mid+1, se, qs, qe, 2*index+2));
}

int SegmentTree::query(int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        // cout<<"Invalid Input\n";
        return -1;
    }
 
    return query_solve(0, n-1, qs, qe, 0);
}
 
int SegmentTree::build(int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  max(build(ss, mid, si*2+1),build(mid+1, se, si*2+2));
    return st[si];
}

bool compare(int x,int y,int a[],int n)
{
    int i = x-1, j= y-1;
    while(i<n&&j<n)
    {
        if(a[i]<a[j])
            return true;
        if(a[i]>a[j])
            return false;
        i++;
        j++;
    }
    if(i==n)
        return true;
    if(j==n)
        return false;
}

int main()
{
	init_temp;
	cint(t);
	while(t--)
	{
		cint2(n,m);
		int a[n],b[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i-1];
			b[i] = a[i-1];
			indices[i] = i;		
		}

		SegmentTree Tree(a,n);
		
		build_maxheap(b,n);
		heapsort(b,n);

		ll sum[n+1];
		sum[0] = 0;

        for(i=1;i<n;i++)
        {
            j = i;
            while(j<n && b[i] == b[j+1])
                j++;
            int temp,temp1;
            for (temp = i; temp < j+1; ++temp)
            {
                for (temp1 = temp + 1; temp1 < j+1; ++temp1)
                {
                    if (compare(indices[temp],indices[temp1],a,n))
                    {
                        int a_;
                        a_ =  indices[temp];
                        indices[temp] = indices[temp1];
                        indices[temp1] = a_;
                    }
                }
            }
        }

		for(i=1;i<=n;i++)
		{
			sum[i] = sum[i-1] + (n-indices[i]+1);
			// out2(sum[i],indices[i]);
		}
		while(m--)
		{
			ll x;
			cin>>x;
			ll temp = bs(sum,x,1,n,n);
			// out(temp);
			ll temp1 = indices[temp] - x + sum[temp]; 
			// out2(indices[temp],temp1);  
			out(Tree.query(indices[temp]-1, temp1-1));

		}	
	}
}




