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

vector<vector<int>> adj;
int n, m;
int dp[11][(1 << 11)];
int go(int mask, int prev) {
	int &ans = dp[prev][mask];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!(mask & (1 << i))) {
			if (adj[prev][i] == -1) continue;
			ans = max(ans, adj[prev][i] + go(mask ^ (1 << i), i));
		}
	}
	return ans;
}

void yash()
{
	cin >> n >> m;
	adj.resize(n + 1, vector<int>(n + 1, -1));
	for (int i = 1; i <= n; i++) {
		adj[i][0] = 0;
		adj[0][i] = 0;
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;
	}

	int ans = go(0, 0);
	cout << ans << "\n";
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