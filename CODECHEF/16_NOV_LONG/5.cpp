/*
Author : Ponnada Harsha Vardhan
Institute : IIT Kharagpur
*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int 
#define nl cout<<'\n'
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define mp make_pair
#define MAXINT 2147483647
#define MAXLONG 9223372036854775807 
#define loop(i,a,n) for(i=a;i<n;i++)
#define pb push_back
#define init_temp ll i,j,k 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(i) cout<<"check "<<i;nl
#define cint(a) int a; cin>>a
#define cint2(a,b) cint(a); cint(b)
#define cll(a) ll a; cin>>a
#define cll2(a,b) cll(a); cll(b)
#define out(a) cout<<a<<"\n";
#define out2(a,b) cout<<a<<" "<<b<<"\n";
using namespace std;

 
ll gcd(ll a,ll b)
{
  ll x = max(a,b);
  ll y = min(a,b);
  if(x%y==0)
    return y;
  return gcd(y,x%y);
}
 

//Data declarations glabally
vector < vector< pair <ll,ll> > > graph(50005);
vector <ll> tree(50005),sub(50005);
std::vector<ll> input(50005);
std::vector<ll> visited(50005);
vector<ll> counter(50005);

ll calc(ll root)
{
	ll i;
	visited[root] = 1;
	ll sum = 0, cnt = 0;
	for(i=0;i< graph[root].size();i++)
	{
		if(visited[graph[root][i].first])
			continue;
		if(input[graph[root][i].first])
		{
			sum += graph[root][i].second;
			cnt++;
		}
		int temp = calc(graph[root][i].first);
		cnt += temp;
		sum += graph[root][i].second*temp;
		sum += tree[graph[root][i].first];
	}
	tree[root] = sum;
	counter[root] = cnt;
	return cnt;
}

void calc1(ll root,ll m)
{
	if(root == 1)
		sub[root] = tree[root];
	ll i;
	visited[root] = 1;
	ll sum = 0;
	if(input[root])
		sum = tree[root];
	for(i=0;i<graph[root].size();i++)
	{
		if(visited[graph[root][i].first])
			continue;
		ll temp;
		temp = sub[root];
		temp = temp+(graph[root][i].second)*(m-2*counter[graph[root][i].first]);
		if(input[graph[root][i].first])
			temp -= 2*(graph[root][i].second);
		sub[graph[root][i].first] = temp;
		calc1(graph[root][i].first,m);
	}
}

int main()
{
	BOOST;
	init_temp;
	cint(t);
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(i=0;i<n;i++)
			graph[i].clear();

		for(i=0;i<n-1;i++)
		{
			ll x,y,z;
			cin>>x>>y>>z;
			graph[x].pb(mp(y,z));
			graph[y].pb(mp(x,z));
		}
	
		fill(input.begin(),input.end(),0);
		for(i=0;i<m;i++)
		{
			cll(x);
			input[x] = 1;
		}
		fill(tree.begin(),tree.begin()+n+2,0);
		fill(sub.begin(),sub.begin()+n+2,0);
		fill(visited.begin(),visited.begin()+n+2,0);
		fill(counter.begin(),counter.begin()+n+2,0);
		calc(1); 
		
		fill(visited.begin(),visited.begin()+n+2,0);
		calc1(1,m);

		ll result = 0;
		for(i=1;i<=n;i++)
			if(input[i])
				result += sub[i];

		if(result == 0)
		{
			cout<<"0 1\n";
			continue;
		}
		ll fact = gcd(result,m*m);
		cout<<result/fact<<" "<<(m*m)/fact<<endl;
	}
}