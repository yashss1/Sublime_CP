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
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<vector<pair<int, int>>> adj;

vector<int> dist, vis;
int ff;

bool dfs(int u, int p) {
	int ans = 1;

	for (auto pp : adj[u]) {
		int v = pp.first;
		int d = pp.second;

		if (!vis[v]) {
			vis[v] = 1;
			pos[v] = pos[u] + d;
			ans &= dfs(v, u);
		}

		if (pos[v] - pos[u] != d)
			ans = 0;

		if (ans == 0)
			break;
	}

	return ans;
}

void yash()
{
	int n, m;
	cin >> n >> m;
	adj.clear();
	adj.resize(n + 2);

	map<pair<int, int>, int> mp;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c < 0) {
			swap(a, b);
			c *= -1;
		}

		adj[a].push_back({b, c});
		adj[b].push_back({a, -c});
	}

	dist.clear();
	dist.resize(n + 1, -1);
	vis.clear();
	vis.resize(n + 1, 0);

	ff = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs(i, 0);
		}
	}

	if (ff == 0) {
		cout << "NO\n"; return;
	}
	cout << "YES\n";
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