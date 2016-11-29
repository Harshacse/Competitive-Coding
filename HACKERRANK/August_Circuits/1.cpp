#include <iostream>
using namespace std;
#include <unordered_map>
#define cint(a) int a; cin>>a;


int main()
{
	std::unordered_map<int,int>  prime;
	int i,j,max;
	std::unordered_map<int,int>::const_iterator got;
	std::pair<int,int> myshopping (1,0);
	prime.insert(myshopping); 
	for(i=2;i<=1000;i++)
	{
		got = prime.find (i);
		if(got == prime.end())
		{
			j=2*i;
			while(j<=1000)
			{
			    std::pair<int,int> myshopping (j,0);
				prime.insert(myshopping);
				j+=i;
			}
		}
	}
	cint(t);
	while(t--)
	{
		cint(n);
		max = 0;
		for(i=0;i<n;i++)
		{
			cint(temp);
			got = prime.find (temp);
			if(got == prime.end())
			{
				if(max<temp)
					max=temp;
			}
		}
		if (max)
			cout<<max*max<<'\n';
		else
			cout<<"-1\n";
	}
}