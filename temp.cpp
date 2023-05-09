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
const int N = 1e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m, s, t;
vector<int> adj[N];
vector<int> v(2);
vector<int> dist[2];
vector<int> vis(N, 0);

int dfs(int node, int dest) {
  if (node == v[dest]) {
    return 0;
  }

  vis[node] = 1;
  int ans = INT_MAX;

  if (dist[dest][node] != INT_MAX) {
    return dist[dest][node];
  }

  for (auto it : adj[node]) {
    if (vis[it] == 0) {
      ans = min(ans, 1 + dfs(it, dest));
    }
  }
  dist[dest][node] = ans;
  return ans;
}


void yash()
{
  cin >> n >> m >> s >> t;
  v[0] = s, v[1] = t;
  dist[0].assign(n + 2, INT_MAX);
  dist[1].assign(n + 2, INT_MAX);

  map<pair<int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (u > v) {
      swap(u, v);
    }
    mp[ {u, v}] = 1;
  }
  dist[0][s] = 0;
  dist[1][t] = 0;


  for (int i = 1; i <= n; i++) {
    vis.assign(n + 1, 0);
    dfs(i, 0);
  }

  for (int i = 1; i <= n; i++) {
    vis.assign(n + 1, 0);
    dfs(i, 1);
  }


  // for (int i = 1; i <= n; i++) {
  //  cout << i << " -> " << dist[0][i] << '\n';
  // } cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //  cout << i << " -> " << dist[1][i] << '\n';
  // } cout << '\n';

  int temp = dist[1][s];
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      // path -> s -> i -> j -> t;
      if (mp[ {i, j}] == 1) continue;
      int ans = INT_MAX;
      int t1 = dist[0][i], t2 = 1, t3 = dist[1][j];
      ans = min(ans, t1 + t2 + t3);
      t1 = dist[0][j], t2 = 1, t3 = dist[1][i];
      ans = min(ans, t1 + t2 + t3);


      if (ans >= temp) {
        // cout << i << " -> " << j << " = " << ans << '\n';
        res++;
      }
    }
  }

  cout << res << '\n';

}

signed main()
{
  // init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // test
  yash();
  return 0;
}