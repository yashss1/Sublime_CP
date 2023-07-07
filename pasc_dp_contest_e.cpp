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
const int N = 19;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<int> v(N);
int dp[N][(1 << N)];

int go(int mask, int prev) {
	if (mask == pow(2, n) - 1) {
		return 0;
	}

	int &ans = dp[prev][mask];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (!(mask & (1 << i))) {
			ans = max(ans, abs(v[prev] - v[i]) + go(mask ^ (1ll << i), i));
		}
	}
	return ans;
}
void trace(int mask, int prev) {
	if (mask == pow(2, n) - 1) {
		return;
	}

	int ans = dp[prev][mask];

	for (int i = n - 1; i >= 0; i--) {
		if (!(mask & (1 << i))) {
			int t = abs(v[prev] - v[i]) + go(mask ^ (1ll << i), i);
			if (t == ans) {
				cout << i + 1 << " ";
				trace(mask ^ (1ll << i), i);
				return;
			}
		}
	}
	assert(false);
}

void yash()
{
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	memset(dp, -1, sizeof(dp));
	// sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, go((1ll << i), i));
	}

	cout << ans << '\n';
	for (int i = n; i >= 0; i--) {
		if (go((1ll << i), i) == ans) {
			cout << i + 1 << " ";
			trace((1ll << i), i);
			cout << '\n';
			return;
		}
	}
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