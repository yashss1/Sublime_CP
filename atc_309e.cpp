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
int N = 3e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
https://atcoder.jp/contests/abc309/tasks/abc309_e
7 3
1 2 1 3 3 3
1 1
1 2
4 3
*/

vector<vector<int>> adj;
vector<vector<int>> ans;

int dfs(int node, int par) {
	int dpth = 0;
	ans[0][node] = 1;
	for (auto it : adj[node]) {
		if (it != par) {
			int depth = 1 + dfs(it, node);
			dpth = max(dpth, depth);
			for (int i = 1; i <= depth; i++) {
				ans[i][node] += ans[i - 1][it];
			}
		}
	}
	cout << node << " -> " << ans[2][node] << '\n';

	return dpth;
}

void yash()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	ans.assign(n + 2, vector<int>(n + 2, 0));
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		adj[i].push_back(a);
		adj[a].push_back(i);
	}

	dfs(1, -1);
	for (int i = 0; i <= n; i++) {
		cout << i << " -> ";
		for (int j = 0; j <= n; j++) {
			cout << j << " " << ans[j][i] << "\n";
		}
	}

	while (m--) {
		int x, y;
		cin >> x >> y;


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