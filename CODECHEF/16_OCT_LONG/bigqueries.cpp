#include <bits/stdc++.h>
using namespace std;
#define MAX 200020
#define MOD 1000000007


class SegmentTree
{
    public:
        int *arr;
        int tree[MAX] ;  
        int lazy[MAX] ; 
        int lazy1[MAX] ;
        int count[MAX] ;
        int n;

        SegmentTree(int arr_[],int n_,int type)
        {
        	std::fill(lazy1, lazy1 + MAX, -1);
      		std::fill(lazy, lazy + MAX, 0);
            arr = arr_;
            n = n_;
            build(arr, 0, n-1, 0);
            getcount(type);
            // for(int i=0;i<n;i++)
            // {
            // 	cout<<tree[i]<<'\n';
            // }
            // cout<<'\n';
        }
        void getcount(int type);
        void build(int arr[], int ss, int se, int si);
        void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff);
        // void updatenew(int n, int us, int ue);
        // void updatenewRangeUtil(int si, int ss, int se, int L,
        //              int R);
        void updateRange(int n, int us, int ue, int diff);
        void newupdate(int n, int us, int ue, int diff);
		void newupdateRange(int si, int ss, int se, int us,
                     int ue, int diff);
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
	if(lazy1[si]!=-1)
	{
		tree[si] = (se-ss+1)*lazy[si];
		int l = lazy1[si];
		tree[si] += count[se-l+1]-count[ss-l];
		if (ss != se)
        {
            lazy1[si*2 + 1]   = lazy1[si];
            lazy1[si*2 + 2]   = lazy1[si];
            lazy[si*2 + 1]   = lazy[si];
            lazy[si*2 + 2]   = lazy[si];
        }
        lazy[si] = 0;
        lazy1[si] = -1;
	}
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
 
// void SegmentTree::updatenew(int n, int us, int ue)
// {
//    updatenewRangeUtil(0, 0, n-1, us, ue);
// }

// void SegmentTree::updatenewRangeUtil(int si, int ss, int se, int L,
//                      int R)
// {
// 	if(lazy1[si]!=-1)
// 	{
// 		tree[si] = (se-ss+1)*lazy[si];
// 		l = lazy1[si];
// 		tree[si] += count[se-l+1]-count[ss-l];
// 		if (ss != se)
//         {
//             lazy1[si*2 + 1]   = lazy1[si];
//             lazy1[si*2 + 2]   = lazy1[si];
//             lazy[si*2 + 1]   = lazy[si];
//             lazy[si*2 + 2]   = lazy[si];
//         }
//         lazy[si] = 0;
//         lazy1[si] = -1;
// 	}
// 	if (lazy[si] != 0)
//     {
//         tree[si] += (se-ss+1)*lazy[si];
//         if (ss != se)
//         {
//             lazy[si*2 + 1]   += lazy[si];
//             lazy[si*2 + 2]   += lazy[si];
//         }
//         lazy[si] = 0;
//     }
    
//     if (ss>se || ss>R || se<L)
//         return ;
    
//     if (ss>=L && se<=R)
//     {
//     	tree[si] = 
//         tree[si] += count[se-L+1]-count[ss-L];
//         if (ss != se)
//         {
//             lazyqueue[si*2 + 1].push_back(L);
// 	        lazyqueue[si*2 + 2].push_back(L);  
//         }
//         return;
//     }
//     int mid = (ss+se)/2;
//     updatenewRangeUtil(si*2+1, ss, mid, L, R);
//     updatenewRangeUtil(si*2+2, mid+1, se, L, R);

//     tree[si] = tree[si*2+1] + tree[si*2+2];
// }

void SegmentTree::newupdate(int n, int us, int ue, int diff)
{
	newupdateRange(0, 0, n-1, us, ue, diff);
}

void SegmentTree::newupdateRange(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if(lazy1[si]!=-1)
	{
		tree[si] = (se-ss+1)*lazy[si];
		int l = lazy1[si];
		tree[si] += count[se-l+1]-count[ss-l];
		if (ss != se)
        {
            lazy1[si*2 + 1]   = lazy1[si];
            lazy1[si*2 + 2]   = lazy1[si];
            lazy[si*2 + 1]   = lazy[si];
            lazy[si*2 + 2]   = lazy[si];
        }
        lazy[si] = 0;
        lazy1[si] = -1;
	}

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
        tree[si] = (se-ss+1)*diff;
        tree[si] += count[se-us+1]-count[ss-ue];
        cout<<"tree["<<si<<"] = "<<tree[si]<<endl;
        lazy[si] = 0;
        lazy1[si] = -1;
        if (ss != se)
        {
            lazy1[si*2 + 1] = us;
            lazy1[si*2 + 2] = us;
            lazy[si*2 + 1] = diff;
            lazy[si*2 + 2] = diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    newupdateRange(si*2+1, ss, mid, us, ue, diff);
    newupdateRange(si*2+2, mid+1, se, us, ue, diff);

    tree[si] = tree[si*2+1] + tree[si*2+2];
}


int SegmentTree::getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if(lazy1[si]!=-1)
	{
		tree[si] = (se-ss+1)*lazy[si];
		int l = lazy1[si];
		tree[si] += count[se-l+1]-count[ss-l];
		if (ss != se)
        {
            lazy1[si*2 + 1]   = lazy1[si];
            lazy1[si*2 + 2]   = lazy1[si];
            lazy[si*2 + 1]   = lazy[si];
            lazy[si*2 + 2]   = lazy[si];
        }
        lazy[si] = 0;
        lazy1[si] = -1;
	}
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
        // cout<<"Invalid\n";
        return -1;
    }
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
void SegmentTree::getcount(int type)
{
	int temp, x,i;
	count[0] = 0;
	count[1] = 0;
	for(i=2;i<=10000;i++)
	{
		count[i] = count[i-1];
		x = i;
		while(x%type==0)
		{
			x=x/type;
			count[i]+=1;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,n,m,temp,temp1;
		cin>>n>>m;
		int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		int five[n],two[n];
		for(i=0;i<n;i++)
		{
			five[i] = two[i] = 0;
			temp = a[i];
			while(temp%5 == 0)
			{
				five[i]++;
				temp/=5;
			}
			temp = a[i];
			while(temp%2 == 0)
			{
				two[i]++;
				temp/=2;
			}
		}
		SegmentTree fivetree(five,n,5);
		SegmentTree twotree(two,n,2);

		long long int sum = 0;
		while(m--)
		{
			int type,L,R,x;
			cin>>type;

			if(type==1)
			{
				cin>>L>>R>>x;
				temp = x;
				temp1 = 0;
				while(temp%5 == 0)
				{
					temp/=5;
					temp1 += 1;
				}
				fivetree.updateRange(n,L-1,R-1,temp1);

				temp = x;
				temp1 = 0;
				while(temp%2 == 0)
				{
					temp/=2;
					temp1 += 1;
				}
				twotree.updateRange(n,L-1,R-1,temp1);
			}

			if(type==2)
			{
				cin>>L>>R>>x;
				temp = x;
				temp1 = 0;
				while(temp%5 == 0)
				{
					temp/=5;
					temp1 += 1;
				}
				fivetree.newupdate(n,L-1,R-1,temp1);

				temp1 = 0;
				while(temp%2 == 0)
				{
					temp/=2;
					temp1 += 1;
				}
				twotree.newupdate(n,L-1,R-1,temp1);
			}

			if(type==3)
			{
				cin>>L>>R;
				int temp;
				temp = min(twotree.getSum(n,L-1,R-1),fivetree.getSum(n,L-1,R-1));
				cout<<temp<<'\n';
				sum = (sum+temp)%MOD;
			}
		}
		cout<<sum<<'\n';
	}
}