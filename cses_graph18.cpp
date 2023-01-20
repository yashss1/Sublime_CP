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

int mod_add(int a, int b, int m) {a = a % m; b = b % m; 
return (((a + b) % m) + m) % m;}

// number of ways going from 1 to n
int n, m;
vector<vector<int>> adj;
vector<int> vis(N, 0), dp(N, 0);

void go(int node) {
  vis[node] = 1;
  for(auto it: adj[node]) {
    if(!vis[it]) {
      go(it);
    }
    dp[node] = mod_add(dp[node], dp[it], MOD);
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
  int mx = 0;

  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      go(i);
    }
  }

  cout << dp[1] << '\n';

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