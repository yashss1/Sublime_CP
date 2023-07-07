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

int n, m;
vector<vector<int>> v;

vector<vector<int>> dp;
int go(int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0) {
		return -1e9;
	}
	if (x == 0) {
		return v[x][y];
	}

	int &ans = dp[x][y];
	if (ans != -1) {
		return ans;
	}

	int c2 = v[x][y] + go(x - 1, y - 1);
	int c3 = v[x][y] + go(x - 1, y + 1);
	int c1 = v[x][y] + go(x - 1, y);


	return ans = max({c1, c2, c3});

}

vector<string> res;
void trace(int x, int y, string s) {
	if (x >= n || y >= m || x < 0 || y < 0) {
		return;
	}
	if (x == 0 && s.size() == n - 1) {
		res.push_back(s);
		return;
	}
	if (x == 0) {
		return;
	}
	int ans = dp[x][y];

	int c2 = v[x][y] + go(x - 1, y - 1);
	if (ans == c2) {
		string temp = s;
		temp += "L";
		trace(x - 1, y - 1, temp);
		return;
	}
	int c3 = v[x][y] + go(x - 1, y + 1);
	if (ans == c3) {
		string temp = s;
		temp += "R";
		trace(x - 1, y + 1, temp);
		return;
	}
	int c1 = v[x][y] + go(x - 1, y);
	if (ans == c1) {
		string temp = s;
		temp += "U";
		trace(x - 1, y, temp);
		return;
	}

	// assert(false);
}

void yash()
{
	cin >> n >> m;
	v.assign(n, vector<int>(m));
	dp.assign(n + 2, vector<int>(m + 2, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int ans = 0;
	for (int i = m - 1; i >= 0; i--) {
		ans = max(ans, go(n - 1, i));
	}

	cout << ans << '\n';
	for (int i = m - 1; i >= 0; i--) {
		int temp = go(n - 1, i);
		if (temp == ans) {
			trace(n - 1, i, "");
		}
	}
	sort(all(res));
	// pVec(res);
	cout << res[0] << '\n';
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