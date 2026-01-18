//YashS
#include <bits/stdc++.h>
using namespace std;
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

vector<int> dp;
void go(int idx, vector<int> &v, int forward) {
	int n = v.size();
	if (forward) {
		if (idx == n) {
			return;
		}
	} else {
		if (idx == -1) {
			return;
		}
	}

	if (forward) {
		if (idx > 0) {
			dp[idx] = min(dp[idx], abs(v[idx] - v[idx - 1]));
		}
		go(idx + 1, v, forward);
	} else {
		if (idx < n - 1) {
			dp[idx] = min(dp[idx], abs(v[idx] - v[idx + 1]));
		}
		go(idx - 1, v, forward);
	}
}

void yash(int TEST)
{
	int n;
	cin >> n;
	vector<int> v(n);
	dp.assign(n, 0);
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[i] = v[i];
		ans = min(ans, v[i]);
	}

	go(0, v, 1);
	go(0, v, 0);
	// go(0, v, 1);
	// go(0, v, 0);
	pVec(dp);

	for (int i = 0; i < n; i++ ) {
		ans = max(ans, dp[i]);
	}

	cout << "Case #" << TEST << ": " << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		yash(i + 1);
	}
	return 0;
}