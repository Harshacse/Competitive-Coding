#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define MOD 1000000007

char a[100010],b[100010];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int i,check1,check2;
		
		i = 0;
		check1 = 0;
		while(i<strlen(a))
		{
			if(a[i] == '1')
				i++;
			else
			{
				if(i == strlen(a)-1)
					break;
				else if(i+1 == strlen(a)-1)
					check1 = 1;
				else if(a[i+1] == '1')
					check1 = 1;
				else if(a[i+2] == '2')
					check1 = 1;
				i+=3;
			}
		}

		i = 0;
		check2 = 0;
		while(i<strlen(b))
		{
			if(b[i] == '1')
				i++;
			else
			{
				if(i == strlen(b)-1)
					break;
				else if(i+1 == strlen(b)-1)
					check2 = 1;
				else if(b[i+1] == '1')
					check2 = 1;
				else if(b[i+2] == '2')
					check2 = 1;
				i+=3;
			}
		}

		int count = 0;
		if(check1==0 && check2==0)
		{
			for(i=0;i<strlen(a);i++)
				if(a[i]==b[i])
					count++;
		}
	}
}