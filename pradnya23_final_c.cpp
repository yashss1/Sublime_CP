//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int a[N];
class node {
public:
	static const int inf = 1e18;
	int mn, mx, sum, pos;

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

// Default tasks
// Point assignment with range queries
struct segtree {
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n) {
		N = n;
		st.resize((N << 2) + 2);
		build(1, 1, N);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
	}

	void build (int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(0, 0, a[L]); // initially all zero
			// st[u] = a[L];
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
		if (L == R){ 
			return st[u];
		}
		int M = (L + R) / 2;
		if (pos <= M)
			return pQuery(u * 2, L, M, pos);
		else
			return pQuery(u * 2 + 1, M + 1, R, pos);
	}

	void pUpdate(int u, int L, int R, int pos, int val) {
		if (L == R) {
			// Point update
			// Update leaf value
			// st[u] = node(val, val, val); //ASSIGNMENT
			st[u].sum += node(val, val, val).sum; //SUM
			return;
		}
		int M = (L + R) / 2;
		if (pos <= M)
			pUpdate(u * 2, L, M, pos, val);
		else
			pUpdate(u * 2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	void displaySegmentTree() {
		rep(i, 1, 7 + 1) {
			cout << query(i).sum << " ";
		} cout << "\n";
	}

	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if (L != R)
		{
			cLazy[node * 2] = 1;
			cLazy[node * 2 + 1] = 1;
			lazy[node * 2] += lazy[node];   // += for sum
			lazy[node * 2 + 1] += lazy[node];
		}
		st[node].mn = lazy[node];
		// st[node].sum = (R - L + 1) * lazy[node];  // SUM WHILE ASSIGNMENT
		st[node].sum += (R - L + 1) * lazy[node];  // SUM while incrementing by val
		cLazy[node] = 0;
		// lazy[node] = 0;
	}

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if (cLazy[node])
			propagate(node, L, R);
		if (j < L || i > R)
			return;
		if (i <= L && R <= j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R) / 2;
		Update(node * 2, L, M, i, j, val);
		Update(node * 2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node * 2], st[node * 2 + 1]);
	}

	node query(int pos) { return pQuery(1, 1, N, pos); }

	node query(int l, int r) { return Query(1, 1, N, l, r); }

	void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }

	void update(int l, int r, int val) { Update(1, 1, N, l, r, val);}
};


void yash()
{
  int n, q;
  cin >> n >> q; 
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	a[i + 1] = v[i];
  }

  segtree seg;
  seg.init(n);
  seg.displaySegmentTree();

  vector<int> pref(n);

  while(q--) {
  	int t;
  	cin >> t;
  	if(t == 1) {
  		int x, y;
  		cin >> x >> y;
  		int curr_val = v[x - 1];
  		v[x - 1] = y;
  		// cout << curr_val << " " << y << '\n';
  		seg.update(x, n, (y - curr_val));
  		// seg.displaySegmentTree();
   	}
   	else {
   	}
  }
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // test
  yash();
  return 0;
}