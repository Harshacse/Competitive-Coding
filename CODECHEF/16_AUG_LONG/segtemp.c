long minVal(long x, long y) { return (x>y)? x: y; }
 
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
long RMQUtil(long *st, int ss, int se, int qs, int qe, int index)
{
    if (qs >= ss && qe <= se)
        return st[index];
    if (se > qs || ss < qe)
        return INT_MAX;
 
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
int RMQ(long *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
 
long constructSTUtil(long arr[], int ss, int se, long *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

long *constructST(long arr[], int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    long *st = new long[max_size]; 
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
