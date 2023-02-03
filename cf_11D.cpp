//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 13 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m;
vector<vector<int>> adj;

int dp[N][1 << N];
int go(int mask, int curr_node, int starting_node, int prev_node) {
	int &ans = dp[curr_node][mask];
	if(ans != -1) {
		return ans;
	}

	ans = 0;
	for(int it = starting_node; it < n; it++) { //consists only startingnode to n nodes in the cycle
		if(adj[it][curr_node] && prev_node != it) {
			if(it == starting_node) {
				ans++;
			}
			else if(!(mask & (1 << it))) {
				ans += go(mask ^ (1 << it), it, starting_node, curr_node);
			}
		}
	}
	return ans;
}

void yash()
{
  cin >> n >> m; 
  memset(dp, -1, sizeof(dp));
  adj.resize(n + 1, vector<int>(n + 1));
  for(int i = 0; i < m; i++) {
  	int u, v; cin >> u >> v;
  	u--;
  	v--;

  	adj[u][v] = 1;
  	adj[v][u] = 1;
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
  	int curr = go((1 << i), i, i, -1);
  	// cout << curr << '\n';
  	ans += (curr / 2);
  }

  cout << ans << '\n';
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