#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int count;
	struct node* c[26];
}node;

node* insert1(node *head1,int temp[])
{
	int i;
	if(head1==NULL)
	{
		head1 = (node*)malloc(sizeof(node));
		for(i=0;i<26;i++)
			head1->c[i] = NULL;
		head1->count = 0;
		for(i=0;i<26;i++)
		{
			if(!temp[i])
			{
				head1->count = 1;
				temp[i] = 1;
				head1->c[i] = insert1(head1,temp);
				break;
			}
		}
	}
	else
	{
		printf("check\n");
		for(i=0;i<26;i++)
		{
			printf("check\n");
			if(!temp[i])
			{
				head1->count += 1;
				temp[i] = 1;
				head1->c[i] = insert1(head1,temp);
				break;
			}
		}	
	}
	return head1;
}

node* insert2(node *head1,int temp[])
{
	int i;
	if(head1==NULL)
	{
		head1 = (node*)malloc(sizeof(node));
		for(i=0;i<26;i++)
			head1->c[i] = NULL;
		head1->count = 0;
		for(i=0;i<26;i++)
		{
			if(!temp[i])
			{
				head1->count = 1;
				temp[i] = 1;
				head1->c[i] = insert2(head1,temp);
				break;
			}
		}
	}
	else
	{
		for(i=0;i<26;i++)
		{
			if(temp[i])
			{
				head1->count += 1;
				temp[i] = 0;
				head1->c[i] = insert2(head1,temp);
				break;
			}
		}	
	}
	return head1;
}

int count_num(node* head1, node* head2)
{
	int sum = 0,i;
	for(i=0;i<26;i++)
	{
		if(head1->c[i]==NULL)
		{
			sum+=head1->count;
			continue;
		}
		if(head2->c[i]==NULL)
		{
			continue;
		}
		sum += count_num(head1->c[i],head2->c[i]);
	}
	return sum;
}

int main()
{
	int n1,n2,i,j,length,k;
	scanf("%d %d",&n1,&n2);
	char s1[1000];
	node *head1 = NULL,*head2 = NULL;
	for(i=0;i<n1;i++)
	{
		int temp[26] = {0};
		scanf("%s",s1);
		length = strlen(s1);
		for(j=0;j<length;j++)
			temp[s1[j]-65]++;
		printf("check\n");
		head1 = insert1(head1,temp);
	}
	for(i=0;i<n2;i++)
	{
		int temp[26] = {0};
		scanf("%s",s1);
		length = strlen(s1);
		for(j=0;j<length;j++)
			temp[s1[j]-65]++;
		head2 = insert2(head2,temp);
	}
	printf("%d\n",count_num(head1,head2));
}