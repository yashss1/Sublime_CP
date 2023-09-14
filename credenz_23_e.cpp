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
int N = 1e2 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m, k;
vector<vector<int>> v;

bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
		return false;
	return true;
}

vector<vector<vector<int>>> dp;
int go(int x, int y, int K) {
	if (!check(x, y)) {
		return INT_MAX;
	}
	if (k < 0) {
		return INT_MAX;
	}

	if (x == n - 1 && y == m - 1) {
		return 0;
	}

	int &ans = dp[x][y][K];
	if (ans != -1) {
		return ans;
	}

	int c1 = INT_MAX;
	int c2 = INT_MAX;

	if (v[x][y] == 1) {
		c1 = (K % 2 == 0 ? (-2) : (-1)) + go(x + 1, y, K);
		c2 = (K % 2 == 0 ? (-2) : (-1)) + go(x, y + 1, K);
	}
	else if (v[x][y] == 0) {
		c1 = 1 + go(x + 1, y, K);
		c2 = 1 + go(x, y + 1, K);
	}
	else if (v[x][y] == 2) {
		if (k > 0) {
			c1 = 1 + go(x + 1, y, K - 1);
			c2 = 1 + go(x, y + 1, K - 1);
		}
	}
	else {
		c1 = (v[x][y] % 3) + go(x + 1, y, K - 1);
		c2 = (v[x][y] % 3) + go(x, y + 1, K - 1);
	}

	return ans = min({c1, c2});
}

void yash()
{
	cin >> n >> m >> k;
	v.assign(n, vector<int>(m));


	dp.assign(n + 5, vector<vector<int>>(m + 5, vector<int>(k + 5, -1)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int ans = go(0, 0, k);
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