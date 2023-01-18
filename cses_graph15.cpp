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

// Topological sort
// using set and stack
// set for visited vertices, stack for elements in topological sort
// put vertex in set when all its children are explored\
// when all children are visited print the stack, the stack will contain elements in topological sort

// https://cp-algorithms.com/graph/topological-sort.html#implementation
int n, m; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n + 1, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
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

  topological_sort();

  map<int, int> mp;
  for(int i = 0; i < ans.size(); i++) {
    mp[ans[i]] = i;
  }

  for(int i = 0; i < m; i++){
    if(mp[vec[i].first] > mp[vec[i].second]){
      cout << "IMPOSSIBLE\n";
      return;
    }
  }

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