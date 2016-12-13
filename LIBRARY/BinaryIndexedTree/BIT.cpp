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


    int getSum(int BITree[], int index)
    {
        int sum = 0; 
        index = index + 1;
        while (index>0)
        {
            sum += BITree[index];
            index -= index & (-index);
        }
        return sum;
    }
    void updateBIT(int BITree[], int n, int index, int val)
    {
        index = index + 1;
        while (index <= n)
        {
           BITree[index] += val;
           index += index & (-index);
        }
    }
    int *constructBITree(int arr[], int n)
    {
        int *BITree = new int[n+1];
        for (int i=1; i<=n; i++)
            BITree[i] = 0;
        for (int i=0; i<n; i++)
            updateBIT(BITree, n, i, arr[i]);
        return BITree;
    }


 
 
// Driver program to test above functions
int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
         << getSum(BITree, 5);
 
    // Let use test the update operation
    freq[3] += 6;
    updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]
 
    cout << "\nSum of elements in arr[0..5] after update is "
         << getSum(BITree, 5);
 
    return 0;
}