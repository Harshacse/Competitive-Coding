#include<iostream>
using namespace std;
char s[12350];
int main()
{
	int t,length,i,j,check;
	cin>>t;
	while(t--)
	{
		cin>>s;
		length = 0;
		while(s[length]!='\0')
			length++;
		i = 0;
		j = length-1;
		check = 0;
		while(i<=j)
		{
			if(i==j)
			{
				if(s[i]=='.')
					s[i] = 'a';
			}

			else if(s[i]!=s[j])
			{
				if(s[i]=='.' && s[j]=='.')
				{
					s[i] = 'a';
					s[j] = 'a';
				}
				else if(s[i] == '.'&&s[j]!='.')
					s[i] = s[j];
				else if(s[j] == '.'&&s[i]!='.')
					s[j] = s[i];
				else
					check = -1;
			}
			else if(s[i]==s[j])
			{
				if(s[i]=='.')
					s[i] = s[j] = 'a';
			}
			i++;
			j--;
		}
		if(check == -1)
			cout<<"-1"<<endl;
		else
			cout<<s<<endl;
	}
}