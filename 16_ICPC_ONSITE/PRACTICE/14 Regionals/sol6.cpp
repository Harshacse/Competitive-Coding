#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;
 
#define rep(i, n) for(int i = 0; i < (n); ++i)
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())
 
#define gi(x) scanf("%d", &x)
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "
 
const int N = 100100;
const int K = 16;
const int mod = (int)1e9 + 7;
 
char s[N];
int a[N], id[128];
int nxt[N][K];
int cnt[1 << K], cnt2[1 << K];
 
inline void add(int & x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
 
inline int mul(int x, int y) {
    return (ll)x * y % mod;
}
 
inline int choose(int n) {
    return ((ll)n * (n + 1) / 2) % mod;
}
 
int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    
    for (char ch = '0'; ch <= '9'; ++ch) {
        id[ch] = ch - '0';
    }
 
    for (char ch = 'A'; ch <= 'F'; ++ch) {
        id[ch] = 10 + ch - 'A';
    }
 
    int tests;
    gi(tests);
 
    rep (tc, tests) {
        scanf("%s", s);
        int n = strlen(s);
 
        // dbg(s), dbn;
 
        rep (i, n) a[i] = id[s[i]];
        rep (i, K) nxt[n][i] = -1;
 
        // rep (i, n) dbs(a[i]); dbn;
 
        for (int i = n - 1; i >= 0; --i) {
            rep (j, K) nxt[i][j] = nxt[i + 1][j];
            nxt[i][a[i]] = i;
 
            // dbg(i), dbn;
            // rep (j, K) if (nxt[i][j] != -1) {
            //     dbg(j), dbg(nxt[i][j]), dbn;
            // }
        }
 
        mset(cnt, 0);
 
        rep (i, n) {
            vector <pii> v;
 
            rep (j, K) if (nxt[i][j] != -1) v.pb(mp(nxt[i][j], j));
 
            sort(all(v));
 
            // dbg(i), dbn;
            // rep (j, sz(v)) {
            //     dbs(v[j].ff), dbs(v[j].ss), dbn;
            // }
 
            int curMask = 0;
            rep (j, sz(v)) {
                if (j > 0) {
                    add(cnt[curMask], v[j].ff - v[j - 1].ff);
                }
                curMask |= (1 << v[j].ss);
            }
 
            add(cnt[curMask], n - v.back().ff);
 
            // rep (mask, (1 << K)) if (cnt[mask] > 0) dbg(mask), dbg(cnt[mask]), dbn;
 
        }
 
        rep (i, (1 << K)) {
            cnt2[i] = cnt[i];
 
        }
 
        rep (bit, K) for (int mask = (1 << K) - 1; mask >= 0; --mask) {
            if (mask >> bit & 1) {
                add(cnt2[mask], cnt2[mask ^ (1 << bit)]);
            }
        }
 
        // for (int mask = 0; mask < (1 << K); ++mask) {
        //     int cur = 0;
        //     for (int mask2 = 0; mask2 < (1 << K); ++mask2) {
        //         if ((mask & mask2) == mask2) {
        //             add(cur, cnt[mask2]);
        //         }
        //     }
        //     assert(cur == cnt2[mask]);
        // }
 
        int waste = 0;
        int fullMask = (1 << K) - 1;
 
        rep (mask, (1 << K)) {
            add(waste, mul(cnt[mask], cnt2[fullMask ^ mask]));
        }
 
        int total = mul(choose(n), choose(n));
        int ans = total - waste;
        if (ans < 0) ans += mod;
        pin(ans);
    }
 
    return 0;
} 
Comments 
