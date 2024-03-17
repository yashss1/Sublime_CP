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
const int N = 1e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> dp(N + 1, 1e12);

void solve() {
	dp[1] = 1, dp[3] = 1, dp[6] = 1, dp[10] = 1, dp[15] = 1;
	for (int i = 1; i <= N; i++) {
		if (i >= 1)
			dp[i] = min(dp[i], 1 + dp[i - 1]);
		if (i >= 3)
			dp[i] = min(dp[i], 1 + dp[i - 3]);
		if (i >= 6)
			dp[i] = min(dp[i], 1 + dp[i - 6]);
		if (i >= 10)
			dp[i] = min(dp[i], 1 + dp[i - 10]);
		if (i >= 15)
			dp[i] = min(dp[i], 1 + dp[i - 15]);
	}
}

void yash()
{
	int n;
	cin >> n;
	/*
	1 = 1
	2 = 2
	3 = 1
	4 = 2
	5 =
	*/



	// for (int i = 1; i <= n; i++) {
	//     cout << dp[i] << "\n";
	// }
	// cout << dp[n] << '\n';

	int ans = (n / 15);
	int rem = n % 15;

	int t = 50;
	int res = INT_MAX;
	for (int i = 0; i < t; i++) {
		int curr = ans + dp[rem];
		res = min(res, curr);
		if (rem > n || ans == 0) {
			break;
		}
		rem += 15;
		ans--;
	}

	cout << res << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	test
	yash();
	return 0;
}