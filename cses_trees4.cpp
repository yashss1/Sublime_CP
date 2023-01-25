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
vector<int> vis(N, 0), ans(N, 0);

int bfs(int node) {
  int top;
  queue<int> q;
  vector<int> d(n+1, -1);
  d[node] = 0;
  ans[node] = max(ans[node], d[node]);
  q.push(node);
 
  while(!q.empty()) {
    top = q.front();
    q.pop();
 
    for(int v: adj[top]) {
      if(d[v] == -1) {
        q.push(v);
        d[v] = d[top] + 1;
        ans[v] = max(ans[v], d[v]);
      }
    }
  }
  return top;
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

  int diam_end_1 = bfs(1);
  int diam_end_2 = bfs(diam_end_1);
  bfs(diam_end_2);
 
  for(int i = 1; i <= n ; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
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