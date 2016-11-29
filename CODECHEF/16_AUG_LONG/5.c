#include <iostream>
#include <math.h>
using namespace std;

#define MAX 16

typedef struct tree
{
    long end;
    long index;
    struct tree *left,*right;
}node;

long long_bin(long num,long *ans)
{
    long a[16],count=0,i,j;
    while(num!=0)
    {
        a[count] = num%2;
        num = num/2;
        count+=1;
    }
    i = 0;
    j=count;
    while(j)
    {
        ans[i] = a[j-1];
        j--;
        i+=1;
    }
    return count;
}

node *insertnode(node *head,long data)
{
    long bits[15],i,count;
    node *root = head;
    count = long_bin(data,bits);
    for(i=0;i<count;i++)
    {
        if(head == NULL)
        {
            head = (node*)malloc(sizeof(node));
            head->left = head->right = NULL;
            head->end = 0;
            root = head;
        }
        if(bits[i])
        {
            if(root->right == NULL)
            {
                root->right = new node();
                root->right->left = root->right->right = NULL;
                root->right->end = 0;
            }
            root = root->right;
        }
        if(!bits[i])
        {
            if(root->left == NULL)
            {
                root->left = new node();
                root->left->left = root->left->right = NULL;
                root->left->end = 0;
            }
            root = root->left;   
        }
    }
    root->end = 1;
    return head;
}

long maxVal(long x, long y) { return (x > y)? x: y; }
long getMid(long s, long e) {  return s + (e -s)/2;  }
long RMQUtil(long *st, long ss, long se, long qs, long qe, long index)
{
    if (qs >= ss && qe <= se)
        return st[index];

    if (se > qs || ss < qe)
        return long_MAX;
    long mid = ss + (se-ss)/2;
    return (RMQUtil(st, ss, mid, qs, qe, 2*index+1)>RMQUtil(st, mid+1, se, qs, qe, 2*index+2))?(RMQUtil(st, ss, mid, qs, qe, 2*index+1):RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

long RMQ(long *st, long n, long qs, long qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        prlongf("Invalid Input");
        return -1;
    }
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

long constructSTUtil(long arr[], long ss, long se, long *st, long si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    long mid = getMid(ss, se);
    st[si] =  maxVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

long *constructST(long arr[], long n)
{
    long x = (long)(ceil(log2(n))); 
    long max_size = 2*(long)pow(2, x) - 1; 
    long *st = new long[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}


int main()
{
    node *head = NULL;    
    long n,data,i,bits[16];

    long max[n];
    // for(i=0;i<n;i++)
    // {
    //     scanf("%d",&data);
    //     if(!i)
    //     {
    //         max[0] = data;
    //         head = insertnode(head,data);
    //     }
    //     else
    //     {
    //         if(max[i-1]>data)
    //     }
    // }
}