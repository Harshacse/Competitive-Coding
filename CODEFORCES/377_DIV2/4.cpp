#include<bits/stdc++.h>
using namespace std;
int n, m, exam[100005], day[100005], taken[100005];
typedef pair<int,int> ii;


bool solvable(int key)
{
	int done = 0;
	memset(taken, 0, sizeof taken);
	vector<ii> review;
	for(int i=key; i>=1; i--)
	{
		if((exam[i] == 0 || taken[exam[i]]))
		{
			if(review.empty()) continue;
			review.back().second--;
			if(review.back().second == 0)
			{
				printf("Done %d on %d day\n",review.back().first,i);
				review.pop_back();
				done ++;
			}
		}
		else
		{
			review.push_back(ii(exam[i],day[exam[i]]));
			taken[exam[i]] = 1;
			printf("Taken %d on %d day\n", exam[i], i);
		}
	}
	return done == m;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&exam[i]);
	for(int i=1; i<=m; i++) scanf("%d",&day[i]);
	if(!solvable(n))
	{
		printf("-1\n");
		return 0;
	}
	int low = 1, high = n;
	while(low<high)
	{
		int mid = ((low+high)>>1);
		if(solvable(mid)) high = mid;
		else low = mid + 1;
	} 
	if(solvable(low)) printf("%d\n",low);
	else printf("-1\n");
	return 0;
}