#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int t;
	int n,m;
	int x,y;
	int i,j,check1,check2,check,result,temp,count,task;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		std::vector< vector<int> > data(n+1, vector<int>(n+1,0) );
		std::vector<int> visit(n),visit1;
		vector< vector<int> > myvector(2,std::vector<int>(0)); 

		for(i=0;i<n;i++)
			visit[i] = i+1;
		while(m--)
		{
			cin>>x>>y;
			data[x][y] = data[y][x] =1;
		}

		result = 0;
	
		while(visit.size()!=0)
		{
			visit1.clear();
			myvector[0].clear();
			myvector[1].clear();
			myvector[0].push_back(visit[0]);
			for(j=1;j<visit.size();j++)
			{
				i = visit[j];
				if(data[1][i]==0)
					myvector[1].push_back(i);
				visit1.push_back(i);
			}
			visit.clear();
			// cout<<visit1.size()<<'\n';

			for(j=0;j<visit1.size();j++)
			{
				i = visit1[j];
				check1 = 0;
				check2 = 0;
				for (std::vector<int>::iterator it=myvector[0].begin(); it!=myvector[0].end(); ++it)
	    		{
	    			if(i==*it)
	    				continue;
	    			if(data[*it][i]==0)
	    			{
	    				check1 = 1;
	    				break;
	    			}
	    		}

	    		for (std::vector<int>::iterator it=myvector[1].begin(); it!=myvector[1].end(); ++it)
	    		{
	    			if(i==*it)
	    				continue;
	    			if(data[*it][i]==0)
	    			{
	    				check2 = 1;
	    				break;
	    			}
	    		}

	    		if(check1 == 1 && check2 == 1)
	    		{
	    			result = -1;
	    			break;
	    		}

	    		if(check1 == 1 && check2 == 0)
	    			myvector[1].push_back(i);

	    		if(check1 == 0 && check2 == 1)
	    			myvector[0].push_back(i);

	    		if(check1 == 0 && check2 == 0)
	    			visit.push_back(i);
	    		// cout<<i<<" "<<check1<<" "<<check2<<'\n';
			}
			if(result==-1)
				break;
		}
		
		if(result==-1)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		else
		{
			cout<<"YES"<<'\n';
		}
	}
}