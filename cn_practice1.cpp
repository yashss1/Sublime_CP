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

// dhanraj Codenation: print the max partial tree sum.
/*
7
1 2 3 -3 4 10 -4
1 2
1 3
3 4
3 5
4 6
4 7
*/

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
int n, m;
vector<vector<int>> adj;
vector<int> subTreeSum(N, 0);
vector<int> v(N);
vector<int> ans(N);

void dfs(int node, int par) {
	subTreeSum[node] = v[node];
  
	int curr = 0;
	for(auto it: adj[node]) {	
		if(it != par) {
			dfs(it, node);
			if (subTreeSum[it] > 0) {
				curr += subTreeSum[it];
			}
		}
	}
	subTreeSum[node] += curr;
}


void go(int node, int par) {
	int par_sum = (par == -1 ? -1 : ans[par]);
	int curr = (subTreeSum[node]>0 ? (par_sum) : (par_sum + subTreeSum[node]));
	if(node != 1){
		ans[node] = curr;
	}

	for(auto it: adj[node]) {	
		if(it != par) {
			go(it, node);
		}
	}
}


void yash()
{
  cin >> n;
  adj.resize(n + 1);
  vector<pair<int, int>> vec;
  for(int i = 1; i <= n; i++) {
  	cin >> v[i];
  }

  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1 ,-1);
  ans[1] = subTreeSum[1];
  go(1, -1);

  for(int i = 1; i <= n; i++) {
  	cout << i << " -> " << ans[i] << '\n';
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