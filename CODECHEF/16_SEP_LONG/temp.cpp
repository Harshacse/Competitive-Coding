#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int t;
	int n,m;
	int x,y;
	int i,j,check1,check2,check,result,temp;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		std::vector< vector<int> > data(n+1, vector<int>(n+1,0) );
		std::vector<int> visit;
		vector< vector<int> > myvector(2,std::vector<int>(0)); 

		while(m--)
		{
			cin>>x>>y;
			data[x][y] = data[y][x] =1;
		}
		result = 0;
		myvector[0].push_back(1);
		for(j=2;j<=n;j++)
		{
			if(data[1][j]==0)
				myvector[1].push_back(j);
		}

		for(j=2;j<=n;i++)
		{
			i = visit1[j]
			check1 = 0;
			check2 = 0;
			for (std::vector<int>::iterator it=myvector[0].begin(); it!=myvector[0].end(); ++it)
    		{
    			if(data[*it][i]==0)
    			{
    				check1 = 1;
    				break;
    			}
    		}

    		for (std::vector<int>::iterator it=myvector[1].begin(); it!=myvector[1].end(); ++it)
    		{
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

    		if(check1 == 1&& check2 == 0)
    			myvector[1].push_back(i);

    		if(check1 == 0&& check2 == 1)
    			myvector[0].push_back(i);

    		if(check1 == 0&& check2 == 0)
    			visit.push_back(i);
		}

		if(result==-1)
		{
			cout<<"No"<<endl;
			continue;
		}
		while(1)
		{
			std::vector<int> visit1 = visit;
			vector< vector<int> > myvector(2,std::vector<int>(0)); 
			myvector[0].push_back(1);
			for(j=1;j<visit1.size();j++)
			{
				i = visit[j];
				if(data[1][i]==0)
					myvector[1].push_back(i);
			}
			std::vector<int> visit;
			for(j=0;j<visit1.size();j++)
			{
				i = visit[j];
				check1 = 0;
				check2 = 0;
				for (std::vector<int>::iterator it=myvector[0].begin(); it!=myvector[0].end(); ++it)
	    		{
	    			if(data[*it][i]==0)
	    			{
	    				check1 = 1;
	    				break;
	    			}
	    		}

	    		for (std::vector<int>::iterator it=myvector[1].begin(); it!=myvector[1].end(); ++it)
	    		{
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

	    		if(check1 == 1&& check2 == 0)
	    			myvector[1].push_back(i);

	    		if(check1 == 0&& check2 == 1)
	    			myvector[0].push_back(i);

	    		if(check1 == 0&& check2 == 0)
	    			cout<<"what!?"<<endl;
			}
		}
		if(result==-1)
		{
			cout<<"No"<<endl;
			continue;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
}