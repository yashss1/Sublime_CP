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
vector<int> parent(N, 0);
pair<int, int> temp = {-1, -1};

void dfs(int node, int par) {
  vis[node] = 1;
  parent[node] = par;
  for(auto it : adj[node]) {
    if(vis[it] == 1 && par != it) {
      // cycle found
      temp = {node, it};
    } 
    else if(vis[it] == 0) {
      dfs(it, node);
    }
  }
}

void yash()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int gotIt = 0;
  for(int i = 1; i <= n; i++) {
      if(vis[i] == 0) {
      dfs(i, -1);
      if(temp.first != -1 && temp.second != -1){
        gotIt = 1;
        break;
      }
    }
  }

  // cout << temp.first << " " << temp.second << '\n';
  // return;

  if (gotIt == 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  vector<int> ans;
  int start = temp.first, curr = temp.second;
  ans.push_back(start);
  ans.push_back(curr);

  while (start != curr){
    int par = parent[curr];
    ans.push_back(par);

    curr = par;
  }

  cout << ans.size() << "\n";
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