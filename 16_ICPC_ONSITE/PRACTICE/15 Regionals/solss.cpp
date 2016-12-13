#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define maxN		5005
using namespace std;
int C[maxN][maxN];
int dp[maxN];
int pow25[maxN];
void solve(){
	int n;
	cin>>n;
	cout<<dp[n]<<endl;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pow25[0]=1;
	rep(i,1,maxN)pow25[i]=(pow25[i-1]*25LL)%hell;
	int t=1;
	C[0][0]=1;
	rep(i,1,maxN){
		C[i][0]=1;
		C[i][i]=1;
		rep(j,1,i/2+1){
			C[i][j]=C[i][i-j]=(C[i-1][j]+C[i-1][j-1])%hell;
		}
	}
	rep(i,0,maxN){
		rep(j,1,maxN){
			C[j][i]=(C[j][i]+C[j-1][i])%hell;
		}
	}
	rep(i,1,maxN){
		rep(j,1,i+1){
			int temp=C[i-1][j-1];
			temp=(1LL*temp*temp)%hell;
			dp[i]=(dp[i]+((26LL*pow25[j-1])%hell)*temp)%hell;
		}
	}
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 