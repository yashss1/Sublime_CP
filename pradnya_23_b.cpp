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

int n;
vector<int> adj[N];
vector<int> v(N);
vector<int> children(N), level(N);
vector<pair<int, int>> adj2[N];

int flag = 0;
int dfs(int node, int par, int lvl) {
	vector<int> temp;
	for(auto it: adj[node]) {
		if(it != par) {
			int curr = dfs(it, node, lvl + 1);
			temp.push_back(curr);
		}
	}
	if(temp.size() == 0) {
		return 0;
	}
	sort(all(temp), greater<int>());


	int ans = 0;
	int sz = temp.size();

	int cnt = 1, j = 0;
	while(j < sz) {
		ans = max(ans, temp[j] + cnt);
		j += v[node];
		cnt++;
	}

	return ans;
}

int ans = 0;
int reach = 0;
void leafs(int node, int par, int curr) {
	for(auto it: adj[node]) {
		if(it != par) {
			leafs(it, node, curr);
		}
	}
	if(adj[node].size() > 1) {
		if(v[node] == 0) {
			flag = 1;
		}
	}
}

void yash()
{
 	cin >> n; 
 	v.assign(n + 1, 0);
 	ans = 0;
 	reach = 0;
 	flag = 0;
 	for(int i = 0; i <= n + 2; i++) {
 		adj[i].clear();
 	}
 	for(int i = 1; i <= n; i++) {
 		cin >> v[i];
 	}

 	for(int i = 0; i < n - 1; i++) {
 		int u, v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}
 	leafs(1,-1, 0);
 	if(flag == 1) {
 		cout << "-1\n";
 		return;
 	}

 	int ans = dfs(1, -1, 1);

 	cout << ans << '\n';
 	return;
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