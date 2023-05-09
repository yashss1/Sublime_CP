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
const int N = 1e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m, s, t;
vector<int> adj[N];
int dist[2][N];
vector<int> vis(N, 0);

int dfs(int node, int dest) {
	if (node == dest) {
		return 0;
	}

	vis[node] = 1;
	int ans = INT_MAX;

	for (auto it : adj[node]) {
		if (vis[it] == 0) {
			ans = min(ans, 1 + dfs(it, dest));
		}
	}

	return ans;
}

void bfs(int node) {
	queue<int>q;
	memset(dist[node != s], 63, sizeof dist[node != s]);
	q.push(node);
	dist[node != s][node] = 0;
	while (q.size()) {

		auto cur = q.front(); q.pop();

		for (auto v : adj[cur])if (dist[node != s][v] > dist[node != s][cur] + 1) {
				dist[node != s][v] = dist[node != s][cur] + 1;
				q.push(v);
			}

	}
}


void yash()
{
	cin >> n >> m >> s >> t;
	// dist[0].assign(n + 2, INT_MAX);
	// dist[1].assign(n + 2, INT_MAX);
	memset(dist[0], 63, sizeof dist[0]);
	memset(dist[1], 63, sizeof dist[1]);

	map<pair<int, int>, int> mp;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if (u > v) {
			swap(u, v);
		}
		mp[ {u, v}] = 1;
	}
	dist[0][s] = 0;
	dist[1][t] = 0;


	for (int i = 1; i <= n; i++) {
		vis.assign(n + 1, 0);
		dist[0][i] = dfs(i, s);
	}

	for (int i = 1; i <= n; i++) {
		vis.assign(n + 1, 0);
		dist[1][i] = dfs(i, t);
	}


	int temp = dist[1][s];

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// path -> s -> i -> j -> t;
			if (mp[ {i, j}] == 1) continue;

			int ans = INT_MAX;
			int t1 = dist[0][i], t2 = 1, t3 = dist[1][j];
			ans = min(ans, t1 + t2 + t3);
			t1 = dist[0][j], t2 = 1, t3 = dist[1][i];
			ans = min(ans, t1 + t2 + t3);


			if (ans >= temp) {
				res++;
			}
		}
	}

	cout << res << '\n';

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