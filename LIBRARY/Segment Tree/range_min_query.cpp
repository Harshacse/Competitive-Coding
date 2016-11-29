#include <iostream>
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
        int minVal(int x, int y) { return (x < y)? x: y; }
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
        return INT_MAX;
    int mid = getMid(ss, se);
    return minVal(query_solve(ss, mid, qs, qe, 2*index+1),query_solve(mid+1, se, qs, qe, 2*index+2));
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
    st[si] =  minVal(build(ss, mid, si*2+1),build(mid+1, se, si*2+2));
    return st[si];
}


int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    SegmentTree Tree(arr,n);
    int qs = 0;  
    int qe = n-1;  
    cout<<"    Minimum of values in range ["<<qs<<","<<qe<<"] is = "<<Tree.query(qs, qe)<<endl;
    return 0;
}
