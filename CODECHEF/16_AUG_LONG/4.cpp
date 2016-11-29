#include<iostream>
using namespace std;

long int INF = 9223372036854775807;

int main()
{
	long int k = 1;
	long int t,n,i,x,y,hd,md,check,check1,start,end,start1,end1,temp1,temp2;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long int h[n],m[n];
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			h[i] = (x);
			m[i] = (y);
		}
		if(n==1)
		{
			cout<<"1"<<'\n';
			cout<<"0 Inf"<<'\n';
			continue;
		}
		start = 0;
		end = INF;
		start1 = 0;
		end1 = INF;
		check = 0;
		check1 = 0;
		for(i=1;i<n;i++)
		{
			md = m[i]-m[i-1];
			hd = h[i]-h[i-1];

			if(check==0)
			{
				if(md==0)
				{
					if(hd<=0)
					{
						check = -1;
					}
				}
				else if(hd/md<0)
				{

					if(hd>0)
					{
						temp1 = hd;
						temp2 = -1*md;
						if(temp1%temp2==0)
						{
							if(start>temp1/temp2-1)
								check = -1;
							else
							{
								end= min(end,temp1/temp2-1);
							}
						}
						else
						{
							if(start>temp1/temp2)
								check = -1;
							else
							{
								end= min(end,temp1/temp2);
							}
						}
					}
					else
					{
						temp1 = -1*hd;
						temp2 = md;
						if(end<temp1/temp2+1)
							check = -1;
						else
						{
							start= max(start,temp1/temp2+1);
						}
					}
				}
				else if(hd/md>0)
				{
					if(hd<0)
						check = -1; 
				}
				else if(hd/md==0)
				{
					if(md>0)
						start = max(start,k);
					if(md<0)
						check = -1;
				}
			}

			if(check==1)
			{
				if(md==0)
				{
					if(hd>=0)
						check = -1;
				}
				else if(hd/md<0)
				{

					if(hd<0)
					{
						temp1 = -1*hd;
						temp2 = md;
						if(temp1%temp2==0)
						{
							if(start>temp1/temp2-1)
								check = -1;
							else
							{
								end= min(end,temp1/temp2-1);
							}
						}
						else
						{
							if(start>temp1/temp2)
								check = -1;
							else
							{
								end= min(end,temp1/temp2);
							}
						}
					}
					else
					{
						temp1 = hd;
						temp2 = -1*md;
						if(end<temp1/temp2+1)
							check = -1;
						else
						{
							start= max(start,temp1/temp2+1);
						}
					}
				}
				else if(hd/md>0)
				{
					if(hd>0)
						check = -1; 
				}
				else if(hd/md==0)
				{
					if(md<0)
						start = max(start,k);
					if(md>0)
						check = -1;
				}
			}

			if(check1==1)
			{
				if(md==0)
				{
					if(hd<=0)
					{
						check1 = -1;
					}
				}
				else if(hd/md<0)
				{

					if(hd>0)
					{
						temp1 = hd;
						temp2 = -1*md;
						if(temp1%temp2==0)
						{
							if(start1>temp1/temp2-1)
								check1 = -1;
							else
							{
								end1= min(end1,temp1/temp2-1);
							}
						}
						else
						{
							if(start1>temp1/temp2)
								check1 = -1;
							else
							{
								end1= min(end1,temp1/temp2);
							}
						}
					}
					else
					{
						temp1 = -1*hd;
						temp2 = md;
						if(end1<temp1/temp2+1)
						{
							check1 = -1;
						}
						else
						{
							start1= max(start1,temp1/temp2+1);
						}
					}
				}
				else if(hd/md>0)
				{
					if(hd<0)
						check1 = -1; 
				}
				else if(hd/md==0)
				{
					if(md>0)
						start1 = max(start1,k);
					if(md<0)
						check1 = -1;
				}
			}

			if(check1 == 0)
			{
				if(md==0)
				{
					if(hd>=0)
					{
						check1 = -1;
					}
				}
				else if(hd/md<0)
				{

					if(hd<0)
					{
						temp1 = -1*hd;
						temp2 = md;
						if(temp1%temp2==0)
						{
							if(start1>temp1/temp2-1)
								check1 = -1;
							else
							{
								end1= min(end1,temp1/temp2-1);
							}
						}
						else
						{
							if(start1>temp1/temp2)
								check1 = -1;
							else
							{
								end1= min(end1,temp1/temp2);
							}
						}
					}
					else
					{
						temp1 = hd;
						temp2 = -1*md;
						if(end1<temp1/temp2+1)
							check1 = -1;
						else
						{
							start1= max(start1,temp1/temp2+1);
						}
					}
				}
				else if(hd/md>0)
				{
					if(hd>0)
						check1 = -1; 
				}
				else if(hd/md==0)
				{
					if(md<0)
						start1 = max(start1,k);
					if(md>0)
						check1 = -1;
				}
			}

			
			if(check1==-1 && check==-1)
				break;
			else
			{
				if(check!=-1)
					check = (check+1)%2;
				if(check1!=-1)
					check1 = (check1+1)%2;
			}
		}
		//cout<<"start"<<start<<" end"<<end<<" start1"<<start1<<" end1"<<end<<'\n';
		if(check1==-1&&check==-1)
		{
			cout<<"0"<<'\n';
			continue;
		}
		if(check1!=-1&&check!=-1)
		{
			cout<<"2"<<'\n';
			if(start<start1)
			{
				if(end<INF)
					cout<<start<<" "<<end<<'\n';
				else
					cout<<start<<" Inf"<<'\n';
				if(end1<INF)	
					cout<<start1<<" "<<end1<<'\n';
				else
					cout<<start1<<" Inf"<<'\n';
			}
			else
			{
				if(end1<INF)	
					cout<<start1<<" "<<end1<<'\n';
				else
					cout<<start1<<" Inf"<<'\n';
				if(end<INF)
					cout<<start<<" "<<end<<'\n';
				else
					cout<<start<<" Inf"<<'\n';
			}
		}
		else 
		{
			cout<<"1"<<'\n';
			if(check!=-1)
			{
				if(end<INF)
					cout<<start<<" "<<end<<'\n';
				else
					cout<<start<<" Inf"<<'\n';
			}
			else
			{
				if(end1<INF)	
					cout<<start1<<" "<<end1<<'\n';
				else
					cout<<start1<<" Inf"<<'\n';
			}
		}
	}
}