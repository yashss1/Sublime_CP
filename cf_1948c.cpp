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

int n;
vector<string> v;

vector<vector<int>> dp;

int go(int idx, int row) {
	if (idx >= n) {
		return 0;
	}

	if (idx == n - 1) {
		if (row == 1) {
			return 1;
		}
		return 0;
	}

	int c1 = 0, c2 = 0, c3 = 0;

	int &ans = dp[row][idx];
	if (ans != -1) {
		return ans;
	}

	// move forward
	if (idx <= n - 1 && v[row][idx + 1] != '<') {
		c1 = go(idx + 2, row);
	}
	// move up
	if (row == 1 && v[0][idx] != '<') {
		c2 = go(idx + 1, 0);
	}
	// move down
	if (row == 0 && v[1][idx] != '<') {
		c3 = go(idx + 1, 1);
	}
	// dont move back

	return ans = c1 | c2 | c3;
}

void yash()
{
	cin >> n;
	v.resize(2);
	cin >> v[0] >> v[1];

	dp.assign(2, vector<int>(n + 1, -1));
	// pVec(dp[0]);
	// pVec(dp[1]);

	int ans = go(0, 0);
	if (ans) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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