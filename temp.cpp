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
vector<int> v(N);
vector<int> vis(N + 1, 0), cost(N + 1, 0), dp(N + 1, 0);
int mx;

void dfs(int node, int cst) {
  vis[node] = 1;
  cost[node] = cst;
  mx = max(mx, cost[node]);
  for (auto it : adj[node]) {
    if (vis[it] == 0) {
      dfs(it, cst + v[it]);
    }
  }
}

int ans = 0;
void dfs2(int node, int par) {
  vector<int> temp;
  for (auto it : adj[node]) {
    if (it != par) {
      dfs2(it, node);
      temp.push_back(it);
    }
  }

  if (temp.size() == 0) {
    // ans += (mx - cost[node]);
    dp[node] = (mx - cost[node]);
  }
  else if (temp.size() == 2) {
    ans += (abs(dp[temp[0]] - dp[temp[1]]));
    dp[node] = min(dp[temp[0]], dp[temp[1]]);
  }
  else {
    assert(false);
  }
}

void yash()
{
  int n;
  cin >> n;
  ans = 0, mx = INT_MIN;
  for (int i = 2; i <= n; i++) {
    cin >> v[i];
  }
  if (ceil(log2(n + 1)) != floor(log2(n + 1))) {
    // cout << n << '\n';
    // return;
    assert(false);
  }

  dp.assign(N, 0);
  cost.assign(N, 0);
  vis.assign(N, 0);

  for (int i = 0; i <= n + 2; i++) {
    adj[i].clear();
  }

  for (int i = 1; i <= n; i++) {
    if (i * 2 <= n) {
      adj[i].push_back(i * 2);
      adj[i * 2].push_back(i);
    }
    if ((i * 2) + 1 <= n) {
      adj[i].push_back((i * 2) + 1);
      adj[(i * 2) + 1].push_back(i);
    }
  }

  dfs(1, 0);
  // cout << mx << '\n';
  // for (int i = 1; i <= n; i++) {
  //   cout << i << " -> " << cost[i] << "\n";
  // }
  // cout << '\n';
  dfs2(1, -1);
  cout << ans << '\n';
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