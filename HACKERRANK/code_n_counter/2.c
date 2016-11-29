#include<stdio.h>
#include<stdlib.h>

char* removeChar( char* str, int index )
{
	int i, count =0;
	char *strN = (char*)malloc(sizeof(char)*20);
	for(i=0;i<strlen(str);i++)
	{
		if(i>index)
		{
			strN[count] = str[i];
			count++;
		}
	}

	return strN;
}

void printSub ( char* fixedStr, char* iterStr, int lenFix, int lenIter )
{
	//printf("-- %s %s %d %d\n", fixedStr, iterStr, lenFix, lenIter);

	char *fixedString = (char*)malloc(sizeof(char)*20);
	strcpy(fixedString, fixedStr);

	if(lenFix!=0)
		printf("%s\n", fixedString);

	if(lenIter == 1)
		printf("%s%s\n",fixedStr, iterStr);
	else if(lenIter > 1)
	{
		int i;
		for(i=97;i<=122;i++)
		{
			int k;
			for(k=0;k<lenIter;k++)
			{
				if((int)iterStr[k] == i)
				{
					fixedString[lenFix] = iterStr[k];
					printSub(fixedString, removeChar(iterStr, k), lenFix+1, lenIter-k-1);
				}
			}
		}
	}

}

int main()
{
	int n, i;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		char *str = (char*)malloc(sizeof(char)*20);
		scanf("%s",str);

		int len = strlen(str);

		int j;
		for(j=0;j<strlen(str);j++)
		{
			if((int)str[j] < 97)
				str[j] = str[j] + 32;
		}

		char *fixedStr = (char*)malloc(sizeof(char)*20);
		char *iterStr = (char*)malloc(sizeof(char)*20);

		fixedStr = "";
		strcpy(iterStr, str);

		printSub(fixedStr, iterStr, 0, strlen(str));
	}
}