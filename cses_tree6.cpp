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

int n, q;
vector<vector<int>> adj;
vector<int> ans(N, 0), subtreeAns(N, 0), subtreeSize(N, 0);

int up[N][20];  // NlogN

void binary_lifting(int node, int par)
{
    up[node][0] = par;
    for(int i = 1; i < 20; i++)
    {
        if(up[node][i-1] != -1)
            up[node][i] = up[up[node][i-1]][i-1];  // up[node][2^i level above] -> up[x][2^(i - 1) level] ; x node is -> 2^(i - 1) level above this node
        else up[node][i] = -1;
    }
 
    for(int it : adj[node])
    {
        if(it != par)
            binary_lifting(it, node);
    }
}
 
int ans_query(int node, int jump_required)
{
    if(node == -1 || jump_required == 0)
        return node;
    
    // breaking k in bits, and jumping from maximum (two power) set bit
    for(int i = 19; i >= 0; i--){
        if(jump_required >= (1<<i)){
            return ans_query(up[node][i], jump_required - (1<<i));
        }
    }
    return 1;
}
 
void yash()
{
  cin >> n >> q;
  adj.resize(n + 1);
  vector<pair<int, int>> vec;
  for(int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    adj[u].push_back(i);
    adj[i].push_back(u);
  }

  
  binary_lifting(1, -1);
  while(q--){
      int node, k;
      cin >> node >> k;
      cout << ans_query(node, k) << '\n';
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