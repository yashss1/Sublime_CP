#include "bits/stdc++.h"
using namespace std;
#define F first
#define S second
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef pair<int, int> ii;
const int N =  1e3 + 5;
vector<int>adj[N];
int dist[2][N];
int n, m, s, t;
bool mat[N][N];

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
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

int main() {
	init_code();

	scanf("%d%d%d%d", &n, &m, &s, &t); --s, --t;

	while (m--) {
		int u, v; scanf("%d%d", &u, &v);  --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		mat[u][v] = mat[v][u] = 1;
	}

	bfs(s); bfs(t);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)if (!mat[i][j] && dist[0][i] + 1 + dist[1][j] >= dist[0][t] && dist[1][i] + 1 + dist[0][j] >= dist[0][t])++ans;

	printf("%d\n", ans);

	return 0;
}
