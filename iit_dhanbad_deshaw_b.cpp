//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
Given a tree, and value to each node.
You want to print the sum of max path, such that you cannot use an edge twice
You have to start from 1 and end your path at 1.
You can teleport to any node from any other node atmost one time.


5
1 2 3 4 5
1 2
1 3
2 4
2 5

ANS = 11
*/

vector<int> adj[N];
vector<int> nodeAns;

int dfs(int node, int par, vector<int> &val) {
	int ans = 0;
	for (auto it : adj[node]) {
		if (it != par) {
			ans = max(ans, dfs(it, node, val));
		}
	};
	ans += val[node - 1];
	nodeAns[node] = ans;
	return ans;
}

void yash()
{
	int n;
	cin >> n;
	vector<int> val(n);
	nodeAns.resize(n + 1, 0);
	for (int i = 0; i < n; i++) { // 0 indexed
		cin >> val[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, val);

	vector<int> temp;
	for (auto it : adj[1]) {
		temp.push_back(nodeAns[it]);
	}
	sort(temp.begin(), temp.end(), greater<int>());

	int ans = val[0];
	int t = min(2ll, (long long)temp.size());
	for (int i = 0; i < t; i++) {
		ans += temp[i];
	}

	cout << ans << '\n';
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