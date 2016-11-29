#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

typedef struct node
{
	int end;
	struct node* child[26];
}node;

node* insert(char* string,node* head)
{
	if(head==NULL)
	{
		head = (node*)malloc(sizeof(node));

	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int v,q;
		scanf("%d %d",&v,&q);
		char voc[v][20];
		node *head = NULL;
		for(int i=0;i<v;i++)
		{
			scanf("%s",voc[i]);
			head = insert(voc[i],head);
			char temp[20];
			strcpy(temp,voc[i]);
			sort(temp.begin(),temp.end());
			printf("%s\n",temp);
		}
	}
}