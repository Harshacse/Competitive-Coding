#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
#define min(a,b) (a>b)?b:a
#define LENGTH 6

typedef struct node
{
	int end;
	struct node* child[26];
}node;

node* insert(char* string,node* man)
{
	// printf("%s\n",string);
	node *head = man;
	int i;
	if(man==NULL)
	{
		// printf("check\n");
		man = (node*)malloc(sizeof(node));
		man->end = -1;
		for(i=0;i<26;i++)
			man->child[i] = NULL;
		head = man;
		if(strlen(string)==1)
		{
			head->child[string[0]-97] = (node*)malloc(sizeof(node));
			for(i=0;i<26;i++)
				head->child[string[0]-97]->child[i] = NULL;
			head->child[string[0]-97]->end += 1;
			return man;
		}		
		else
			head->child[string[0]-97] = insert(string+1,head->child[string[0]-97]);
	}
	else
	{
		if(strlen(string)==1)
		{
			head->child[string[0]-97] = (node*)malloc(sizeof(node));
			for(i=0;i<26;i++)
				head->child[string[0]-97]->child[i] = NULL;
			head->child[string[0]-97]->end += 1;
			return man;
		}		
		else
			head->child[string[0]-97] = insert(string+1,head->child[string[0]-97]);
	}
	return man;
}

void print(node *head)
{
	int i;
	if(head==NULL)
		return;
	for(i=0;i<26;i++)
	{
		if(head->child[i]!=NULL)
		{
			// printf("head->child[%d] started:\n",i);
			print(head->child[i]);
		}
	}
}
void sort(char* string,int n)
{
	int i,j;
	char temp;
	//n = strlen(string);
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (string[i] > string[j])
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
}

int check(node*head, char*temp)
{
	int i;
	node *h = head;
	for(i=0;i<strlen(temp);i++)
	{
		if(h->child[temp[i]-97]==NULL)
			return -1;
		else
			h = h->child[temp[i]-97];
	}
	if(h==NULL)
		return -1;
	if(h->end!=-1)
		return h->end;
}

int count(char* string,node *head)
{
	int i,sum = 0;
	char temp[LENGTH];
	if(strlen(string)==0)
		return 1;
	for(i=0;i<min(strlen(string),LENGTH);i++)
	{
		// printf("%s\n",temp);
		temp[i] = string[i];
		sort(temp,i+1);
		temp[i+1] = '\0';
		printf("%s\n",temp);
		int temp1 = check(head,temp);
		if(temp1=-1)
			sum += (temp1+1)*count(string+i+1,head);
	}
	return sum;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	int caseno=1;
	while(t--)
	{
		int v,q;
		scanf("%d %d",&v,&q);
		char voc[v][LENGTH];
		node *head = NULL;
		for(i=0;i<v;i++)
		{
			scanf("%s",voc[i]);
			char temp[LENGTH];
			strcpy(temp,voc[i]);
			sort(temp,strlen(temp));
			// printf("%s\n",temp);
			head = insert(temp,head);
			print(head);
		}
		printf("Case #%d:",caseno);
		char query[4005];
		for(i=0;i<q;i++)
		{
			scanf("%s",query);
			printf(" %d",count(query,head));
		}
		printf("\n");
		caseno++;
	}
}