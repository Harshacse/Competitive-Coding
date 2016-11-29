#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

#define INT_MAX 999999999999
#define MAX 16

#define max(a,b) ((a)>(b)?(a):(b))

long map[1000][1000];

void pre_handle(long * m , int n)
{
    memset(map, 0, sizeof(map));
    for(int i=0;i<n;i++)
        map[i][0]=m[i];
    int k = (int)(log(n) / log(2));
    for(int i=1;i<=k;i++)     
        for(int j = 0; j + pow(2,i-1) < n; j++)
            map[j][i]=max(map[j][i-1], map[j+(int)pow(2, i-1)][i-1]);
}

long RMQ(int a, int b)
{
    int k = (int)(log(b-a+1)/log(2)); 
    return max(map[a][k], map[b+1-(int)pow(2, k)][k]);
}

class node
{
    public:
    int end;
    int index,cnt;
    long value;
     node *left,*right;
};

int int_bin(long num,int *ans)
{
    int a[16],count=0,i,j;
    while(num!=0)
    {
        a[count] = num%2;
        num = num/2;
        count+=1;
    }
    i = 0;
    j=count;
    for(i=0;i<16-j;i++)
        ans[i]=0;
    while(j)
    {
        ans[i] = a[j-1];
        j--;
        i+=1;
    }
    return 16;
}

node *insertnode(node *head,long data,int ind)
{
    int bits[15],i,count;
    node *root = head;
    count = int_bin(data,bits);
    for(i=0;i<count;i++)
    {
        if(head == NULL)
        {
            head = new node();
            head->left = head->right = NULL;
            head->end = 0;
            head->index = -1;
            head->cnt=0;
            head->value = 0;
            root = head;
        }
        if(bits[i])
        {
            if(root->right == NULL)
            {
                root->right = new node();
                root->right->left = root->right->right = NULL;
                root->right->end = 0;
                root->right->cnt=0;
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
                root->left->cnt=0;
            }
            root = root->left;   
        }
    }
    root->end = 1;
    root->cnt += 1;
    root->index = ind;
    root->value = data;
    return head;
}

void printTree(node *head,int *bits,int i)
{   
    int j;
    if(head == NULL)
        return;
    if(head->end)
    {
        for(j=0;j<i;j++)
            cout<<bits[j];
        cout<<endl;
    }
    bits[i] = 0;
    printTree(head->left,bits,i+1);
    bits[i] = 1;
    printTree(head->right,bits,i+1);
}


void check1(node* head,int* bits,int i,long* ans,int ind,int n,long data)
{
    if(head==NULL)
        return;
    if(head->end==1)
    {
        // cout<<"+++ check1: ind: "<<head->index<<", maximum element for ind: "<<ind<<" is "<<RMQ(head->index,ind)<<'\n';
        *ans += head->cnt* RMQ(head->index,ind);
    }
    if(bits[i]==0)
    {
        check1(head->left,bits,i+1,ans,ind,n,data);
        check1(head->right,bits,i+1,ans,ind,n,data);
    }
    else
    {
        check1(head->right,bits,i+1,ans,ind,n,data);
    }
}

void check2(node* head,int* bits,int i,long* ans,int ind,int n,long data)
{
    if(head==NULL)
        return;
    if(head->end==1)
    {
        if(head->value==data)
            return;
        // cout<<"+++ check2: ind: "<<head->index<<", maximum element for ind: "<<ind<<" is "<<RMQ(head->index,ind)<<'\n';
        *ans += head->cnt* RMQ(head->index,ind);

    }
    if(bits[i]==1)
    {
        check2(head->left,bits,i+1,ans,ind,n,data);
        check2(head->right,bits,i+1,ans,ind,n,data);
    }
    else
    {
        check2(head->left,bits,i+1,ans,ind,n,data);
    }
}

void calculate(node *head,long data,long *ans,int ind,int n)
{
    int bits[16],count;
    count = int_bin(data,bits);
    check1(head,bits,0,ans,ind,n,data);
    check2(head,bits,0,ans,ind,n,data);
}

int main()
{
    node *head = NULL;
    int i,n,bits[16];    
    long ans;
    cin >> n;
    long max[n],arr[n];
    for(i=0;i<n;i++)
        cin >> arr[i];
    pre_handle(arr,n);
    ans = 0;
    head = insertnode(head,arr[0],0);
    for(i=1;i<n;i++)
    {
        // cout<<"i= "<<i<<endl;
        calculate(head,arr[i],&ans,i,n);
        head = insertnode(head,arr[i],i);
        int_bin(arr[i],bits);
        printTree(head,bits,0);
    }
    cout<<ans<<'\n';
}