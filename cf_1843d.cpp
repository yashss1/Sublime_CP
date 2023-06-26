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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> adj[N];
vector<int> leafNodesBelow;

int dfs(int node, int par) {
	int sz = 0, fl = 0;
	for (auto it : adj[node]) {
		if (it != par) {
			sz += dfs(it, node);
			fl = 1;
		}
	}
	if (fl == 0) sz = 1;

	leafNodesBelow[node] = sz;
	return sz;
}

void yash()
{
	int n;
	cin >> n;
	leafNodesBelow.assign(n + 1, 0);
	for (int i = 0; i < n + 1; i++) {
		adj[i].clear();
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);
	// for (int i = 1; i <= n; i++) {
	// cout << i << " -> " << leafNodesBelow[i] << '\n';
	// }

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		int ans = leafNodesBelow[x] * leafNodesBelow[y];
		cout << ans << '\n';
	}
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