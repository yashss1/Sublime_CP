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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m;
vector<vector<int>> adj;
vector<int> vis(N, 0), dist(N, 0), children(N, 0);

void dfs_in_subtree(int node, int par) {
  dist[node] = 1;
  children[node] = 1;
  for(auto it : adj[node]) {
    if(it != par) {
      dfs_in_subtree(it, node);
      children[node] += children[it];
    }
  }

  for(auto it : adj[node]) {
    if(it != par) {
      dfs_in_subtree(it, node);
      dist[node] += (dist[it] + ((children[it] - 1)));  // sum of distances of node
    }
  }
}

void dfs2(int node, int par) {
  int t = dist[node];
  for(auto it : adj[node]) {
    if(it != par) {
      dfs2(it, node);
      if(par == 1) continue;
      // dist[node] += (dist[par] - (dist[node] - 1) - children[it]);
      // dist[node] += (dist[it] + ((children[it] - 1)));  // parent_sum - remaing child added
    }
  }
}
 
void yash()
{
  cin >> n;
  adj.resize(n + 1);
  vector<pair<int, int>> vec;
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    vec.push_back({u, v});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_in_subtree(1, -1);
  dfs2(1, -1);


  for(int i = 1; i <= n; i++) {
    cout << i << " -> " << dist[i] << '\n';
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