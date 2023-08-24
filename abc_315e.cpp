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

vector<int> ans;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
	vis[node] = 1;
	for (auto it : adj[node]) {
		if (vis[it] == 0) {
			dfs(it, adj, vis);
			ans.push_back(it);
		}
	}
}


void yash()
{
	int n;
	cin >> n;
	vector<vector<int>> adj;
	adj.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int t; cin >> t;
			adj[i + 1].push_back(t);
		}
	}

	// for (int i = 1; i <= n; i++) {
	//   cout << i << " -> ";
	//   for (auto it : adj[i]) {
	//     cout << it << ' ';
	//   } cout << '\n';
	// }

	ans.clear();
	vector<int> vis(n + 1, 0);
	dfs(1, adj, vis);
	pVec(ans);
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