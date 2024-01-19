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
vector<int> clr, vis;

bool ans;
void dfs(int node, int color, int par) {
	if (ans == false) {
		return;
	}
	if (vis[node] == 1) {
		if (clr[node] != color) {
			ans = false;
			return;
		}
	}
	clr[node] = color;
	vis[node] = 1;
	// cout << node << " -> " << color << '\n';
	for (auto it : adj[node]) {
		// cout << it << "\n";
		if (it == par) continue;

		dfs(it, color ^ 1, node);

		if (ans == false) {
			return;
		}
	}
}

void yash()
{
	int n, m;
	cin >> n >> m;
	clr.assign(n + 5, 0);
	vis.assign(n + 5, 0);
	vector<int> A(m), B(m);

	for (int i = 0; i < n + 2; i++) {
		adj[i].clear();
	}
	map<pair<int, int>, int> mp;
	for (int i = 0; i < m; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		a = A[i], b = B[i];
		if (a > b) {
			swap(a, b);
		}
		// cout << a << " " << b << '\n';
		// if (mp[ {a, b}] == 0) {
		adj[a].push_back(b);
		adj[b].push_back(a);
		mp[ {a, b}] = 1;
		// }
	}

	ans = true;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			// cout << i << '\n';
			ans = true;
			dfs(i, 0, -1);
			if (ans == false) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
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