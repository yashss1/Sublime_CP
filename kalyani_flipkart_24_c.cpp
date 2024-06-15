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
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
INPUT:
8
10 15 21 25 14 22 15 24
7 2
0 1
0 2
1 3
1 4
2 5
3 6
3 7
4

OUTPUT:
15
*/

vector<int> adj[200000];
vector<int> inorder;

void dfs(int node) {
	if (adj[node].size() >= 1)
		dfs(adj[node][0] * -1);
	inorder.push_back(node);
	if (adj[node].size() >= 2)
		dfs(adj[node][1]);
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int c, r;
	cin >> c >> r;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		if (adj[u].size() == 0) {
			adj[u].push_back(v * (-1));
		}
		else {
			adj[u].push_back(v);
		}
	}

	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	int m;
	cin >> m;

	dfs(0);

	int ans = v[inorder[m - 1]];
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