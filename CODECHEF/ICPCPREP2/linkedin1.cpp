/*
 * Complete the function below.
 */
int maxElement(vector < int > arr) {
    sort(arr.begin(),arr.end());
    int i,j,k,n=arr.size();
    for(i=n-1 ; i>=2 ; i--)
    {
        int l=0,r=i-1;
        while(l<r)
        {
            if(arr[l]+arr[r]==arr[i])
                return arr[i];
            else if(arr[l]+arr[r]>arr[i])
                r--;
             else
                l++;
        }
        
    }
    return -1;
}

