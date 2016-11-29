#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	vector< vector<int> > lazyqueue(10000, vector<int>(0) );
	while(t--)
	{
		int n,i,check,check1,check2,ans;
		char l1[1005],l2[1005],l3[1005];
		cin>>l1>>l2>>l3>>n;
		int count1=0,count2_1=0,count2_2=0,count3=0;
		
		i=strlen(l3)-1;
		check=0;
		while(i>=0)
		{
			if(l3[i]=='0')
				check = 1;
			if(check==1&&l3[i]=='1')
				count1++;
			i--;
		}

		check1 = check;
		i=strlen(l2)-1;
		while(i>=0)
		{
			if(l2[i]=='0')
				check = 1;
			if(check==1&&l2[i]=='1')
				count2_1++;
			if(l2[i]=='1')
				count2_2++;
			i--;
		}
		
		check2=check;
		i=strlen(l1)-1;
		while(i>=0)
		{
			if(l1[i]=='0')
				check = 1;
			if(check==1&&l1[i]=='1')
				count3++;
			i--;
		}
		// cout<<"counts: "<<count1<<" "<<count2_1<<" "<<count2_2<<" "<<count3<<", checks: "<<check1<<" "<<check2<<" "<<check<<endl;
		if(check1==0)
		{
			if(check2==0)
			{
				ans = count3 + 1;
				cout<<ans<<'\n';
			}
			else
			{
				ans = count3 + count2_2*(n-1)+ count2_1+1;
				cout<<ans<<'\n';
			}
		}
		else
		{
			ans = count1 + n*count2_1 + count3 + 1;
			cout<<ans<<'\n';
		}

	}
}