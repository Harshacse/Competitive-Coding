/*
	Author : Ponnada Harsha Vardhan
	Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
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
#define init_temp int i,j,k 
#define ll_init_temp ll i,j,k
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
#include <math.h>

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
        int maxVal(int x, int y) { return (x > y)? x: y; }
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
    return maxVal(query_solve(ss, mid, qs, qe, 2*index+1),query_solve(mid+1, se, qs, qe, 2*index+2));
}

int SegmentTree::query(int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input\n";
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
    st[si] =  maxVal(build(ss, mid, si*2+1),build(mid+1, se, si*2+2));
    return st[si];
}


// int main()
// {
//     int n,i;
//     cin>>n;
//     int arr[n];
//     for(i=0;i<n;i++)
//         cin>>arr[i];
//     SegmentTree Tree(arr,n);
//     int qs,qe;
//     cin>>qs>>qe; 
//     cout<<"    Minimum of values in range ["<<qs<<","<<qe<<"] is = "<<Tree.query(qs, qe)<<endl;
//     return 0;
// }


void inttobin(int a,int b[])
{
	int t = a;
	int i = 0;
	while(i<32)
	{
		a[i] = t%2;
		t/=2;
		i++;
	}
}



int main()
{
	init_temp;
	cint(t);
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			for(j=0;j<32;j++)
				prefix[i][j] = 0;


		int b[32];
		inttobin(a[0],b);
		for(i=0;i<32;i++)
			prefix[0][i] = b[i];
		for(i=1;i<n;i++)
		{
			inttobin(a[i],b);
			for(j=0;j<32;j++)
			{
				if(prefix[i-1][j]==1||b[j]==1)
					prefix[i][j] =1;
				else
					prefix[i][j]=0;
			}
		}

		out(count(a));
	}
}