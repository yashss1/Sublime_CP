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

int n, k;
vector<vector<int>> v;

// int go(int idx, int j) {
// 	// cout << idx << " " << j << '\n';
// 	if (idx <= 0) {
// 		return 0;
// 	}

// 	// skip this row
// 	int c1 = go(idx - 1, j);

// 	// take this row's max from {idx, j} in row idx
// 	int mx = INT_MIN;
// 	for (int i = idx; i <= j; i++) {
// 		mx = max(mx, v[idx][i]);
// 	}
// 	int c2 = mx + go(idx - 2, idx - 2);

// 	return max({c1, c2});
// }

int go(int idx) {
	if (idx >= n) {
		return 0;
	}

	int ans = INT_MIN;
	for (int i = idx; i < n; i++) {
		// stop here
		ans = max(ans, v[idx][i] + go(i + 2));
	}

	// skip this
	ans = max(ans, go(idx + 1));
	return ans;
}

void yash()
{
	cin >> n >> k;
	v.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int x;
			cin >> x;
			v[i][j] = x;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		} cout << " | " << i << '\n';
	}

	// int j = 0;
	// vector<int> dp(n);
	// for (int i = 1; i < n; i++) {
	// 	// skip this -> go to
	// 	dp[i] = dp[i - 1];
	// 	// take this -> from ()
	// 	dp[i] = mx + dp[i - 2]; // mx only from  v[i - 2][i - 2] to v[i - 2][j]
	// }

	// j = n - 1;
	// for (int i = n - 1; i >= 0; i--) {
	// 	// skip this -> go(i - 1, j);
	// 	// take -> go(i - 2, i - 2); (find max from v[i][i] to v[i][j]) and j = i - 2;

	// }

	int ans = go(0);
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