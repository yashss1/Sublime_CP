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
map<pair<int, int>, pair<int, int>> parent;
map<pair<int, int>, int> vis;
pair<int, int> temp = {-1, -1};


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
        return false;
    if (vis[{x, y}])
        return false; // If visited returns false
    if(adj[x][y] == '#') return false;
    return true;
}

void dfs(pair<int, int> node, pair<int, int> par) {
  vis[{node.first, node.second}] = 1;
  parent[{node.first, node.second}] = {par.first, par.second};
    

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
    dfs(i, -1);
    if(temp.first == -1 && temp.second == -1){
      gotIt = 1;
      break;
    }
  }

  if (gotIt == 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  while (1){

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