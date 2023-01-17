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
vector<int> adj[N];
vector<int> vis(N, 0);
vector<int> clr(N, -1);
int not_possible = 0;

void dfs(int node) {
  vis[node] = 1;
  for(auto it : adj[node]) {
    if(vis[it] == 1) continue;

    if(clr[it] != -1) {
      if(clr[it] == clr[node]){
        not_possible = 1;
      }
      else {
        dfs(it);
      }
    }
    else {
      clr[it] = (clr[node] ^ 1);
      dfs(it);
    }
  }

}

void yash()
{
  cin >> n >> m;
  vector<pair<int, int>> vec;

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    vec.push_back({u, v});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) {
    if(vis[i] == 0) {
      clr[i] = 0;
      dfs(i);
    }
  }

  for(int i = 1; i <= n; i++){
    vis[i] = 0;
    if(clr[i] == -1) {
      not_possible = 1;
    }
  }

  // checking
  for(int i = 0; i < m; i++){
    if(clr[vec[i].first] == clr[vec[i].second]) {
      not_possible = 1; 
    }
  }

  if(not_possible == 1) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  for(int i = 1; i <= n; i++){
    if(clr[i] == -1) {
      cout << "IMPOSSIBLE\n";
      return;
    }

    cout << clr[i] + 1 << ' ';
  }
  cout << "\n";
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