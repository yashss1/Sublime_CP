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

vector<pair<int, int>> adj[N];

void yash()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 5; i++) {
		adj[i].clear();
	}

	map<pair<int, int>, int> color;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		if (u > v) swap(u, v);
		color[ {u, v}] = w;
	}

	// for (auto it : color) {
	// 	cout << it.first.first << " " << it.first.second << " -> " << it.second << '\n';
	// }

	int start, end;
	cin >> start >> end;

	vector<int> vis(n + 1, 0);

	queue<vector<int>> q; // node, parent, count, color prev
	q.push({0, start, -1, -1});
	vis[start] = 1;

	// cout << start << " " << end << '\n';

	int ans = INT_MAX;
	vector<int> res(n + 1, INT_MAX);
	res[start] = 0;


	vector<int> takeOnly(n + 1, 0);

	vector<int> scam(n + 1, 0);
	scam[start]++;

	while (!q.empty()) {
		vector<int> temp = q.front();
		q.pop();
		if (temp[1] == end) {
			// pVec(temp);
			ans = min(ans, temp[0]);
		}
		// if (takeOnly[temp[1]] != temp[3] && temp[1] != start) {
		// 	continue;
		// }
		for (auto it : adj[temp[1]]) {
			int cnt = temp[0];
			int flag = 0;
			if (color[ {min({temp[2], temp[1]}), max({temp[2], temp[1]})}] != color[ {min({it.first, temp[1]}), max({it.first, temp[1]})}]) {
				cnt++;
				flag = 1;
			}


			// cout << temp[1] << " " << res[temp[1]] << " ||| " << it.first << " " << res[temp[1]] << "\n";

			if (((!vis[it.first]) || (res[it.first] >= res[temp[1]] + flag)) && scam[it.first] <= 36) {
				vis[it.first] = 1;
				res[it.first] = res[temp[1]] + flag;
				takeOnly[it.first] = color[ {min({it.first, temp[1]}), max({it.first, temp[1]})}];

				// cout << temp[1] << " " << it.first << " " << cnt << " -> " << takeOnly[it.first] << '\n';
				scam[it.first]++;
				q.push({cnt, it.first, temp[1], color[ {min({it.first, temp[1]}), max({it.first, temp[1]})}]});
			}
		}

		// cout << "RES -> ";
		// pVec(res);
	}

	cout << ans << '\n';
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