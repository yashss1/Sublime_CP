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


// Longest path in directed acyclic graph
// Here print longest path from 1 to n
int n, m;
vector<vector<int>> adj;
vector<int> vis(N, 0), dp(N, -100000);

void go(int node) {
  vis[node] = 1;
  for(auto it: adj[node]) {
    if(!vis[it]) {
      go(it);
    }
    dp[node] = max(dp[node], 1 + dp[it]);
  }

}

vector<int> path;
void trace(int node) {
  int ans = dp[node];
  for(auto it: adj[node]) {
    int curr = 1 + dp[it];
    if (curr == ans) {
      path.push_back(it);
      trace(it);
      return;
    }
  }
}

void yash()
{
  cin >> n >> m;
  adj.resize(n + 1);
  vector<pair<int, int>> vec;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    vec.push_back({u, v});
    adj[u].push_back(v);
  }


  dp[n] = 1;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      go(i);
    }
  }

  path.push_back(1);
  trace(1);

  if(path[0] != 1 || path[path.size() - 1] != n) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  cout << path.size() << '\n';
  pVec(path);

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