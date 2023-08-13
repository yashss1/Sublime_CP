#include <bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

const int N = 1e5 + 7;

vector<pair<int, int>> adj[N];

int main()
{
	init_code();
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> inDegree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		inDegree[v]++;
	}

	queue<pair<int, int>> q;
	q.push({k, 0});
	vector<int> ans(n + 1, 1000000); // min time it took to reach to this node
	ans[k] = 0;

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		cout << temp.first << " -> ";
		for (auto it : adj[temp.first]) {
			ans[it.first] = min(ans[it.first], it.second + temp.second);
			inDegree[it.first]--;
			cout << it.first << " ";
			if (inDegree[it.first] == 0) {
				q.push({it.first, ans[it.first]});
			}
		}
		cout << '\n';
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, ans[i]);
	}

	for (int i = 1; i <= n; i++) {
		cout << i << " -> " << ans[i] << '\n';
	}

	if (res == 1000000) {
		cout << "-1\n"; return 0;
	}

	cout << res << '\n';
	return 0;
}