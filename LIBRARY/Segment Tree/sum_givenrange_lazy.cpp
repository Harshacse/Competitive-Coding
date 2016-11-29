#include <iostream>
#include<stdio.h>
using namespace std;
#include <math.h>
#define MAX 1000



class SegmentTree
{
    public:
        int *arr;
        int tree[MAX] ;  
        int lazy[MAX] ; 
        int n;
        SegmentTree(int arr_[],int n_)
        {
            arr = arr_;
            n = n_;
            build(arr, 0, n-1, 0);
        }
        void build(int arr[], int ss, int se, int si);
        void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff);
        void updateRange(int n, int us, int ue, int diff);
        int getSum(int n, int qs, int qe);
        int getSumUtil(int ss, int se, int qs, int qe, int si);

} ;

void SegmentTree::build(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return ;

    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se)/2;
    build(arr, ss, mid, si*2+1);
    build(arr, mid+1, se, si*2+2);
 
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}

void SegmentTree::updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
    
    if (ss>se || ss>ue || se<us)
        return ;
    
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

    tree[si] = tree[si*2+1] + tree[si*2+2];
}
 
void SegmentTree::updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
 
int SegmentTree::getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
 
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
 
        lazy[si] = 0;
    }
 
    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
 
int SegmentTree::getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
 


 

 
 
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    SegmentTree tree(arr, n);
 
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
           tree.getSum(n, 1, 3));
 
    // Add 10 to all nodes at indexes from 1 to 5.
    tree.updateRange(n, 1, 5, 10);
 
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
            tree.getSum( n, 1, 3));
 
    return 0;
}