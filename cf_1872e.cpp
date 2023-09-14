//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int a[N], b[N];
class node {
public:
	static const int inf = 1e18;
	int mn, mx, sum;
	node(int _mn, int _mx, int _sum) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
	}
	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
	}
};

int x = 0, y = 0;

vector<int> v;

struct segtree {
	int N;
	vector<node> st;
	vector<int> B;
	vector<bool> cLazy;
	vector<int> lazy;
	void init(int n) {
		N = n;
		st.resize((N << 2) + 2);
		B.resize((N << 2) + 2);
		cLazy.assign((N << 2) + 2, false);
		lazy.assign((N << 2) + 2, 0);
		build(1, 1, N);
	}
	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		// ret.mx = max(left.mx, right.mx);
		ret.mx = left.mx ^ right.mx;
		ret.sum = left.sum + right.sum;
	}

	//Handle lazy propagation appriopriately
	void propagate(int u, int L, int R) {
		// Propagate down?
		if (L != R) {
			cLazy[u * 2] = 1;
			cLazy[u * 2 + 1] = 1;
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			lazy[u * 2] ^= lazy[u];
			// cout << "U * 2 " << (u / 2) << "\n";
			if (lazy[u * 2] == 1) {
				cout << u * 2 << " --> " << B[u * 2] << "\n";
				x ^= B[u * 2];
			}
			else {
				cout << u * 2 << " --< " << B[u * 2] << "\n";
				y ^= B[u * 2];
			}


			lazy[u * 2 + 1] ^= lazy[u];
			// cout << "U * 2 " << ((u - 1) / 2) << "\n";
			if (lazy[u * 2 + 1] == 1) {
				cout << u * 2 + 1 << " ---> " << B[u * 2 + 1] << "\n";
				x ^= B[u * 2 + 1];
			}
			else {
				cout << u * 2 + 1 << " ---< " << B[u * 2 + 1] << "\n";
				y ^= B[u * 2 + 1];
			}
		}
		// Updating the range [L, R] with lazy[u]
		{
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			st[u].sum += (R - L + 1) * lazy[u];
			st[u].mx ^= lazy[u];
			st[u].mn += 1;

			if (st[u].mx == 0) {
				x ^= B[u];
			}
			else {
				y ^= B[u];
			}
		}
		cLazy[u] = 0;
		lazy[u] = 0;
	}
	void build (int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(a[L], a[L], a[L]);
			B[u] = b[L];
			return;
		}
		int M = (L + R) / 2;
		build(u * 2, L, M);
		build(u * 2 + 1, M + 1, R);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}
	node Query(int u, int L, int R, int i, int j) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j < L || i > R)
			return node();
		if (i <= L && R <= j)
			return st[u];
		int M = (L + R) / 2;
		node left = Query(u * 2, L, M, i, j);
		node right = Query(u * 2 + 1, M + 1, R, i, j);
		node ret;
		merge(ret, left, right);
		return ret;
	}
	node pQuery(int u, int L, int R, int pos) {
		if (cLazy[u])
			propagate(u, L, R);
		if (L == R)
			return st[u];
		int M = (L + R) / 2;
		if (pos <= M)
			return pQuery(u * 2, L, M, pos);
		else
			return pQuery(u * 2 + 1, M + 1, R, pos);
	}
	void Update(int u, int L, int R, int i, int j, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j < L || i > R)
			return;
		if (i <= L && R <= j) {
			// Default range update operation is :
			// adding val to all elements in range [...]
			cLazy[u] = 1;
			lazy[u] ^= 1;
			if (lazy[u] == 0) {
				cout << u << " -> " << B[u] << "\n";
				x ^= B[u];
			}
			else {
				cout << u << " -< " << B[u] << "\n";
				y ^= B[u];
			}

			propagate(u, L, R);
			return;
		}
		int M = (L + R) / 2;
		Update(u * 2, L, M, i, j, val);
		Update(u * 2 + 1, M + 1, R, i, j, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}
	void pUpdate(int u, int L, int R, int pos, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (L == R) {
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
			return;
		}
		int M = (L + R) / 2;
		if (pos <= M)
			pUpdate(u * 2, L, M, pos, val);
		else
			pUpdate(u * 2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}
	node query(int pos) { return pQuery(1, 1, N, pos); }
	node query(int l, int r) { return Query(1, 1, N, l, r); }
	void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }
	void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }
};

void yash()
{
	int n;
	cin >> n;
	x = 0, y = 0;
	v.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		b[i + 1] = v[i];
	}
	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		a[i + 1] = s[i] - '0';
		if (s[i] == '1') {
			x ^= v[i];
		}
		else {
			y ^= v[i];
		}
	}

	int q;
	cin >> q;

	segtree seg;
	seg.init(n + 5);

	{
		for (int i = 0; i < n; i++) {
			int t = (seg.query(i + 1).mx);
			cout << t << " ";
		}
		cout << '\n';
	}

	while (q--) {
		int x1;
		cin >> x1;
		if (x1 == 1) {
			int l, r;
			cin >> l >> r;
			seg.update(l, r, 1);

			for (int i = 0; i < n; i++) {
				int t = (seg.query(i + 1).mx);
				cout << t << " ";
			}
			cout << "\n";
		}
		else {
			int y1;
			cin >> y1;

			int t = seg.query(1, n).sum;
			t = max(0ll, t);
			// cout << "Q " << q << '\n';

			cout << "ANS ";
			if (y1 == 1) {
				cout << x << "\n";
			}
			else {
				cout << y << "\n";
			}
		}
	}
	cout << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}