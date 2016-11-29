#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

typedef struct node
{
	int a,b,mon;
}node;

int mini = MOD;
int n,l;

void answer(node* head,int* b,int i,int left,int right,int money)
{
	if(i==n)
	{
		if(left<=l&&right>=l)
			mini = min(mini,money);
		return;
	}
	b[i]=0;
	answer(head,b,i+1,left,right,money);
	b[i]=1;
	answer(head,b,i+1,left+head[i].a,right+head[i].b,head[i].mon+money);
}

int main()
{
	int t;
	cin>>t;
	int caseno=1;
	while(t--)
	{
		int m;
		int i;
		cin>>n>>m>>l;
		node head[n];int b[n];
		for(i=0;i<n;i++)
		{
			cin>>head[i].a>>head[i].b>>head[i].mon;
			b[i] = 0;
		}
		answer(head,b,0,0,0,0);
		cout<<"Case #"<<caseno<<": ";
		if(mini<= m)
			cout<<mini<<endl;
		else
			cout<<"IMPOSSIBLE\n";
		caseno++;
	}
}