#include <iostream>
using namespace std;
#include <math.h>
#define dt int


//SEGMENT TREE BEGINS
class SegmentTree
{
    public:
        dt *st,*arr,n;
        dt getMid(dt s, dt e) {  return s + (e -s)/2;  }
        dt getSumUtil(dt ss, dt se, dt qs, dt qe, dt si);
        void update_query(dt ss, dt se, dt i, dt diff, dt si);
        void update(dt i, dt new_val);
        dt getSum(dt qs, dt qe);
        dt build(dt ss, dt se, dt *st, dt si);
        SegmentTree(dt arr_[], dt n_)
        {
            arr = arr_;
            n = n_;
            dt x = (dt)(ceil(log2(n))); 
            dt max_size = 2*(dt)pow(2, x) - 1; 
            st = new dt[max_size];
            build(0, n-1, st, 0);
        }

};


dt SegmentTree::getSumUtil(dt ss, dt se, dt qs, dt qe, dt si)
{
    if (qs <= ss && qe >= se)
        return st[si];
 
    if (se < qs || ss > qe)
        return 0;
 
    dt mid = getMid(ss, se);
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
 
void SegmentTree::update_query(dt ss, dt se, dt i, dt diff, dt si)
{
    if (i < ss || i > se)
        return;
 
    st[si] = st[si] + diff;
    if (se != ss)
    {
        dt mid = getMid(ss, se);
        update_query(ss, mid, i, diff, 2*si + 1);
        update_query(mid+1, se, i, diff, 2*si + 2);
    }
}
 
void SegmentTree::update(dt i, dt new_val)
{
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input\n";
        return;
    }
 
    dt diff = new_val - arr[i];
 
    arr[i] = new_val;
 
    update_query(0, n-1, i, diff, 0);
}
 
dt SegmentTree::getSum(dt qs, dt qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input\n";
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
dt SegmentTree::build(dt ss, dt se, dt *st, dt si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    dt mid = getMid(ss, se);
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