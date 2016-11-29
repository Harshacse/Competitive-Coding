#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
 
#define forn(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())
 
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "
 
template <class S, class T>
ostream& operator <<(ostream& os, const pair<S, T>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
 
template <class T>
void debug(T a, T b) {
    cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a) cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}
 
const int N = 100100;
const int SIZE = 10;
 
#define l(x) (x << 1) + 1
#define r(x) (x << 1) + 2
#define mid(l, r) ((l + r) >> 1)
 
int a[N];
struct node {
	int cnt[SIZE];
	int toPush;
 
    inline void combine(const node & left, const node & right) {
    	rep (i, SIZE) {
    		cnt[i] = left.cnt[i] + right.cnt[i];
    	}
    }
    
} T[N << 2];
 
struct segmentTree {
    int n;
    
    segmentTree(int m) : n(m) {
        build(0, 0, n - 1);
    }
 
    void build(int x, int l, int r) {
    	T[x].toPush = 0;
        if(l == r) {
        	rep (i, SIZE) T[x].cnt[i] = 0;
        	T[x].cnt[0] = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(l(x), l, m);
        build(r(x), m + 1, r);
        T[x].combine(T[l(x)], T[r(x)]);
    }
 
    inline void resolve(int x, int l, int r) {
        if(T[x].toPush > 0) {
        	int tmp[SIZE];
        	rep (i, SIZE) {
        		int j = (i - T[x].toPush) % SIZE;
        		if (j < 0) j += SIZE;
        		tmp[i] = T[x].cnt[j];
        	}
        	rep (i, SIZE) T[x].cnt[i] = tmp[i];
            if(l != r) {
                T[l(x)].toPush += T[x].toPush;
                T[r(x)].toPush += T[x].toPush;
            }
            T[x].toPush = 0;
        }
    }
 
    void updateRange(int x, int l, int r, int ql, int qr, int v) {
        resolve(x, l, r);
        if(l > qr || r < ql) return;
        if(l >= ql && r <= qr) {
            T[x].toPush = v;
            resolve(x, l, r);
            return;
        }
        int m = (l + r) >> 1;
        updateRange(l(x), l, m, ql, qr, v);
        updateRange(r(x), m + 1, r, ql, qr, v);
        T[x].combine(T[l(x)], T[r(x)]);
    }
 
    node queryRange(int x, int l, int r, int ql, int qr) {
        resolve(x, l, r);
        if(l >= ql && r <= qr) return T[x];
        int m = (l + r) >> 1;
        if(qr <= m) return queryRange(l(x), l, m, ql, qr);
        if(ql > m) return queryRange(r(x), m + 1, r, ql, qr);
        node ret;
        ret.combine(queryRange(l(x), l, m, ql, qr), queryRange(r(x), m + 1, r, ql, qr));
        return ret;
    }
 
    void update(int ql, int qr, int v) {
        updateRange(0, 0, n - 1, ql, qr, v);
    }
 
    node query(int ql, int qr) {
        return queryRange(0, 0, n - 1, ql, qr);
    }
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, q;
	cin >> n >> q;
 
	segmentTree seg(n);
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;
		--l, --r;
		if (type == 1) {
			seg.update(l, r, 1);
		} else {
			node ret = seg.query(l, r);
			int ans = 0;
			rep (i, SIZE) {
				ans += i * ret.cnt[i];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}