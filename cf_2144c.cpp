//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 998244353;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<int> a, b;
vector<vector<int>> dp;

int go(int idx, int swapped) {
	if (idx == n) {
		return 1;
	}

	// int mxInA, mxInB;
	// if (AisA) mxInA = a[mxA];
	// else mxInA = b[mxA];

	// if (BisB) mxInB = b[mxB];
	// else mxInB = a[mxB];

	int &ans = dp[swapped][idx];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	if (swapped == 0) {
		if (a[idx] >= a[idx - 1] && b[idx] >= b[idx - 1]) {
			ans += go(idx + 1, 0);
			ans %= MOD;
		}
		if (b[idx] >= a[idx - 1] && a[idx] >= b[idx - 1]) {
			ans += go(idx + 1, 1);
			ans %= MOD;
		}
	}

	if (swapped == 1) {
		if (a[idx] >= b[idx - 1] && b[idx] >= a[idx - 1]) {
			ans += go(idx + 1, 0);
			ans %= MOD;
		}
		if (b[idx] >= b[idx - 1] && a[idx] >= a[idx - 1]) {
			ans += go(idx + 1, 1);
			ans %= MOD;
		}
	}

	return ans;
}

void yash()
{
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);
	dp.assign(2, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int ans1 = go(1, 0) % MOD;
	int ans2 = go(1, 1) % MOD;
	// cout << ans1 << " " << ans2 << '\n';
	cout << ((ans1 + ans2) % MOD) << '\n';
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