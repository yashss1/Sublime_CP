#include <bits/stdc++.h>

using namespace std;
#define test int T; cin >> T; while (T--)
#define int long long
const int N = 1e5 + 7;

void init_code() {
  #ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
  #endif // ONLINE_JUDGE
}

int n;
vector<int> adj[N];
map<int, int> mp;

void go(int node, int taken, int this_safe, int par) {
	mp[taken]++;
	for(auto it: adj[node]) {
		int t1 = adj[node].size() - 1;
		int c1;
		if(par != it) {
			t1 += this_safe ^ 1;
			go(it, taken + t1, 1, node);
			go(it, taken, 0, node);
		}
	}
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
  	adj[i].clear();
  }
  for(int i = 0; i < n - 1; i++) {
  	int u, v;
  	cin >> u >> v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }

  for(auto it: adj[1]) {
  	go(it, 1, 1, 1);
  	go(it, 0, 0, 1);
  }

  for(int i = 0; i <= n; i++) {
  	cout << mp[i] << '\n';
  }

}

signed main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  test
  solve();
  return 0;
}