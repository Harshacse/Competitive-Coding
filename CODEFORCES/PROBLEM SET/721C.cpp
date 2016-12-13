#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 50;

int deg[maxn] , n , m  , seq[maxn] , cr , T , pos[maxn];
int dp[maxn][maxn];
pair < short , short > pre[maxn][maxn];
vector < pair < int , int > > G[maxn];

queue < int > Q;

inline bool up( int & x , int v ){
	if( v > x ){
		x = v;
		return true;
	}
	return false;
}

vector < int > ans;

int main( int argc , char * argv[] ){
	memset( dp , -1 , sizeof( dp ) );
	scanf("%d%d%d",&n,&m,&T);
	for(int i = 1 ; i <= m ; ++ i){
		int a , b , c;
		scanf( "%d%d%d" , & a ,& b , & c );
		G[a].push_back( make_pair( b , c ) );
		deg[b]++;
	}
	for(int i = 1 ; i <= n ; ++ i) if( deg[i] == 0 ){
		Q.push( i );
	}
	memset( dp , -1 , sizeof( dp ) );
	while( !Q.empty() ){
		int x = Q.front() ; Q.pop();
		seq[ ++ cr] = x;
		pos[x] = cr;
		for(auto it : G[x]){
			int v = it.first;
			deg[v] -- ;
			if( deg[v] == 0 ) Q.push( v );
		}
	}
	dp[1][1] = T;
	for(int i = 1 ; i <= n ; ++ i){
		int x = seq[i];
		for(int j = 0 ; j <= n ; ++ j){
			if( dp[x][j] != -1 ){
				for(auto it : G[x]){
					int v = it.first , c = it.second;
					if( dp[x][j] >= c ){
						if ( up( dp[v][j + 1] , dp[x][j] - c ) ) pre[v][j + 1] = make_pair( x , j );
					}
				}
			}
		}
	}
	int st = n , ti = n;
	for(int i = n ; i >= 0 ; -- i) if( dp[n][i] != -1 ){
		ti = i;
		break;
	}
	ans.push_back( st );
	while( st != 1 ){
		pair < int , int > af = pre[st][ti];
		if( af.second + 1 == ti ) ans.push_back( af.first );
		st = af.first;
		ti = af.second;
	}
	reverse( ans.begin() , ans.end() );
	printf("%d\n",ans.size());
	for(auto it : ans) printf("%d ",it);printf("\n");
	return 0;
}