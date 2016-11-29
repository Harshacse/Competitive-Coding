#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N = 5010;
ll nsplit[N],fact[N];
ll sf[N],ssf[N];
int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		int n;
		ll m;
		cin>>n>>m;
		for(int i=0;i<=n;i++)
		{
			fact[i]=nsplit[i]=sf[i]=ssf[i]=0;
		}
		if(m==1)
		{
			cout<<"Case #"<<z<<": "<<0<<endl;
			continue;
		}
		fact[0]=1;
		for(int i=1;i<=n;i++)
		{
			fact[i]=fact[i-1]*i%m;
		}
		nsplit[1]=1;
		nsplit[2]=1;
		for(int i=3;i<=n;i++)
		{
			nsplit[i]=fact[i];
			for(int j=1;j<i;j++)
			{
				nsplit[i]-=(nsplit[j]*fact[i-j]);
				nsplit[i]%=m;
			}
			nsplit[i]+=m;
			nsplit[i]%=m;
		}
		sf[1]=ssf[1]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				ll sing = sf[i-j]+fact[i-j];
				sing%=m;
				sf[i]+=(sing*nsplit[j]);
				sf[i]%=m;
				sing = ssf[i-j]+2*sf[i-j]+fact[i-j];
				sing%=m;
				ssf[i]+=(sing*nsplit[j]);
				ssf[i]%=m;
			}
		//	cout<<sf[i]<<" "<<ssf[i]<<endl;
			sf[i]+=nsplit[i];
			ssf[i]+=nsplit[i];
			sf[i]%=m;
			ssf[i]%=m;
		//	cout<<sf[i]<<" "<<ssf[i]<<endl;
		}
		cout<<"Case #"<<z<<": "<<ssf[n]<<endl;
	}
}
