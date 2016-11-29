#include "bits/stdc++.h"
using namespace std;
#include <string.h>

int main()
{
	int n,i,j,t;
	cin>>n>>t;
	char s[110];
	vector<int> count(110,0);
	for(i=0;i<n;i++)
	{
		cin>>s;
		count[strlen(s)]++;
	}
	cin>>s;
	int length = strlen(s),sum=0,best,worst;
	for(i=0;i<length;i++)
		sum+= count[i];
	// cout<<sum<<endl;
	best = sum + (sum/t)*5 +1;
	int x = count[length];
	worst = sum + (sum/t)*5 + x + ((sum%t+x)/t)*5;
	if((sum%t+x)%t==0)
		worst -= 5;
	cout<<best<<" "<<worst<<endl;
}