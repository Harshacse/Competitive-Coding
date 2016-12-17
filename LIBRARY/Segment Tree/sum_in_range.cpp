#include <iostream>
using namespace std;
#include <math.h>
#define int int


//SEGMENT TREE BEGINS
class SegmentTree
{
    public:
        int *st,*arr,n;
        int getMid(int s, int e) {  return s + (e -s)/2;  }
        int getSumUtil(int ss, int se, int qs, int qe, int si);
        void update_query(int ss, int se, int i, int diff, int si);
        void update(int i, int new_val);
        int getSum(int qs, int qe);
        int build(int ss, int se, int *st, int si);
        SegmentTree(int arr_[], int n_)
        {
            arr = arr_;
            n = n_;
            int x = (int)(ceil(log2(n))); 
            int max_size = 2*(int)pow(2, x) - 1; 
            st = new int[max_size];
            build(0, n-1, st, 0);
        }

};


int SegmentTree::getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];
 
    if (se < qs || ss > qe)
        return 0;
 
    int mid = getMid(ss, se);
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
 
void SegmentTree::update_query(int ss, int se, int i, int diff, int si)
{
    if (i < ss || i > se)
        return;
 
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        update_query(ss, mid, i, diff, 2*si + 1);
        update_query(mid+1, se, i, diff, 2*si + 2);
    }
}
 
void SegmentTree::update(int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input\n";
        return;
    }
 
    int diff = new_val - arr[i];
 
    arr[i] = new_val;
 
    update_query(0, n-1, i, diff, 0);
}
 
int SegmentTree::getSum(int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input\n";
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
int SegmentTree::build(int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  build(ss, mid, st, si*2+1) +
              build(mid+1, se, st, si*2+2);
    return st[si];
}
//ENDS


//CHECK
int main()
{
    int arr[1000];         
    int i,n;              
    cout<"Give n\n";
    cin>>n;
    cout<<"Give "<<n<<" elements\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    SegmentTree tree(arr,n);
    cout<<"checking sum\nGive l,r\n";
    int l,r;
    cin>>l>>r;
    cout<<"Sum of values in given range = "<<tree.getSum(l,r)<<endl;
    cout<<"checking update\nGive l,r\n";
    cin>>l>>r;
    tree.update(1,10);
    cout<<"Updated sum of values in given range = "<<tree.getSum(l,r)<<endl;
    return 0;
}