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

vector<int> adj[N];
vector<int> temp;
void dfs(int node, int prev) {
	temp.push_back(adj[node].size());
	for (auto it : adj[node]) {
		if (adj[it].size() != prev) {
			dfs(it, adj[node].size());
		}
	}
}

void yash()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		adj[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			temp.clear();
			dfs(i, 1);
			break;
		}
	}

	// for (auto it : temp) {
	// 	cout << it.first << " " << it.second << "\n";
	// }

	int y = temp[1] - 1;
	int x = temp[2];

	cout << x << " " << y << '\n';
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