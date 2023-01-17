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
vector<vector<int>> grps;
vector<int> temp;

void dfs(int node) {
    vis[node] = 1;
    temp.push_back(node);
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it);
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

  for(int i = 1; i < n; i++){
    if(vis[i] == 0) {
        temp.clear();
        dfs(i);
        grps.push_back(temp);
    }
  }

  cout << grps.size() - 1 << '\n';
  vector<pair<int,int>> ans;
  for(int i = 1; i < grps.size(); i++) {
    ans.push_back({grps[i - 1][0], grps[i][0]});
  }

  for(auto it : ans) {
    cout << it.first << ' ' << it.second << '\n';
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