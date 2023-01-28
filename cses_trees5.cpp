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
vector<int> ans(N, 0), subtreeAns(N, 0), subtreeSize(N, 0);

 
void dfs(int src, int par)
{
    int numOfNodes = 1;
    int ansForSubtree = 0;
    for(int child : adj[src])
    {
        if(child != par)
        {
            dfs(child, src);
            numOfNodes += subtreeSize[child];
            ansForSubtree += (subtreeSize[child] + subtreeAns[child]);
        }
    }
    subtreeSize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}
 
 
// ans (c) = subans of (c) + (par ans) +  (nodes in parent tree except the subtree of (c))
void go(int src, int par, int par_ans, int& totalNodes)
{
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
 
    for(int child : adj[src])
    {
        if(child != par)
            go(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
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

  dfs(1, 0);
  go(1, 0, 0, n);
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
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