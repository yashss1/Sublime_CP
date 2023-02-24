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
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m;
vector<int> adj[N];
vector<int> vis(N, 0);
int flag = 0;

int dfs(int node, int par) {
	int res = 1;
	vis[node] = 1;
	for(auto it: adj[node]) {
		if(!vis[it]) {
			res += dfs(it, node);
		}
		else if(it != par) {
			flag = 1;
		}
	}
	return res;
}

void yash()
{
  cin >> n >> m; 
  for(int i = 0; i < n + 2; i++) {
  	adj[i].clear();
  	vis[i] = 0;
  }

  int ans = 0;
  vector<pair<int, int>> v(m);
  for(int i = 0; i < m; i++) {
  	cin >> v[i].first >> v[i].second;
  	if(v[i].first == v[i].second) continue;

  	ans++; 
  	adj[v[i].first].push_back(v[i].second);
  	adj[v[i].second].push_back(v[i].first);
  }

  for(int i = 1; i <= n; i++) {
  	if(!vis[i]) {
  		// dfs(i);
  		flag = 0;
  		dfs(i, -1);
  		ans += flag;
  	}
  }

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