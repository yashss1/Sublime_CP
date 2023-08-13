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
const int N = 4e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> adj[N];

void yash()
{
	int a, b, m;
	cin >> a >> b >> m;
	for (int i = 0; i < a + b + 2; i++) {
		adj[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(a + b + 1, 0);

	queue<pair<int, int>> q;
	q.push({1, 0});
	map<int, int> mp;
	mp[1] = 0;

	while (!q.empty()) {
		pair<int, int> node = q.front();
		vis[node.first] = 1;
		q.pop();

		for (auto it : adj[node.first]) {
			if (vis[it] == 0) {
				vis[it] = 1;
				mp[it] = node.second + 1;
				q.push({it, node.second + 1});
			}
		}
	}


	q.push({a + b, 0});
	map<int, int> mp2;
	mp2[a + b] = 0;

	while (!q.empty()) {
		pair<int, int> node = q.front();
		vis[node.first] = 1;
		q.pop();

		for (auto it : adj[node.first]) {
			if (vis[it] == 0) {
				vis[it] = 1;
				mp2[it] = node.second + 1;
				q.push({it, node.second + 1});
			}
		}
	}


	int mx1 = 0, mx2 = 0;
	for (auto it : mp2) {
		// cout << it.first << " " << it.second << '\n';
		mx1 = max(mx1, it.second);
	}
	for (auto it : mp) {
		// cout << it.first << " " << it.second << '\n';
		mx2 = max(mx2, it.second);
	}

	cout << mx1 + mx2 + 1 << '\n';
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