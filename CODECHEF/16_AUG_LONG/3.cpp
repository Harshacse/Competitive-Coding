#include<iostream>
using namespace std;
int main()
{
	long long int t,n,i,j,sum1,sum2,min1,min2,start,end,ans,temp,min1b,min2b,sum1b,sum2b,ansleft,ansright;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n],front1[n],front2[n],back1[n],back2[n];
		i = 0;
		while(i<n)
		{
			cin >> a[i];
			i++;
		}

		cin>>start>>end;
		start-=1;
		end-=1;
		if(n==1)
			continue;
		sum1=a[start];
		min1=a[start];
		front1[start]=0;
		front1[start+1] = min1;
		for(i=start+1;i<end;i++)
		{
			sum1 += a[i];
			if(min1>sum1)
				min1=sum1;
			front1[i+1] = min1;
		}

		sum1b=0;
		back1[start] = 0;
		temp = (start-1);
		if(temp<0)
			temp+=n;
		sum1b=min1b=a[temp];
		back1[temp]=a[temp];
		temp = (start-2);
		if(temp<0)
			temp+=n;
		i=temp;
		temp = end-1;
		if(temp<0)
			temp+=n;
		while(i!=temp)
		{
			sum1b += a[i];
			if(sum1b<min1b)
				min1b = sum1b;
			back1[i] = min1b;
			i--;
			if(i<0)
				i+=n;
		}
		sum2=a[end];
		min2=a[end];
		back2[end]=0;
		back2[(end+1)%n]=min2;
		for(i=(end+1)%n;i!=start;i=(i+1)%n)
		{
			sum2 += a[i];
			if(min2>sum2)
				min2=sum2;
			back2[(i+1)%n]=min2;
		}

		sum2b=0;
		temp = (end-1);
		sum2b = min2b = a[temp];
		front2[end] = 0;
		front2[temp]= a[temp];
		i = (end-2);
		temp = start-1;
		if(temp<0)
			temp+=n;
		while(i!=temp)
		{
			sum2b += a[i];
			if(sum2b<min2b)
				min2b = sum2b;
			front2[i] = min2b;
			i--;
			if(i<0)
				i+=n;
		}

		ansright = front1[start]+front2[start];
		i = start;
		while(1)
		{
			//cout<<"front1["<<i<<"] = "<<front1[i]<<", front2["<<i<<"] = "<<front2[i]<<'\n';
			if(ansright>front1[i]+front2[i])
				ansright = front1[i]+front2[i];
			if(i==end)
				break;
			i = (i+1)%n;
		}
		ansleft = back1[start]+ back2[start];
		i = start;
		while(1)
		{
			//cout<<"back1["<<i<<"] = "<<back1[i]<<", back2["<<i<<"] = "<<back2[i]<<'\n';
			if(ansleft>back1[i]+back2[i])
				ansleft = back1[i]+back2[i];
			if(i==end)
				break;
			i-=1;
			if(i<0)
				i+=n;
		}

		if(ansleft>0)
			ansleft = 0;
		if(ansright>0)
			ansright = 0;
		ans = (sum1+2*ansleft)<(sum2+2*ansright)?(sum1+2*ansleft):(sum2+2*ansright);
		cout<<ans<<endl;
	}
	return 0;
}