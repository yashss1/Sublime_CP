#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

void solve() {

	ll n;
	cin >> n;

	vector<map<ll, ll>> dp (n);

	bool notPossible = false;

	for (ll i = 0; i < n; i++)
	{
		ll k;
		cin >> k;
		if (k == 0) {
			notPossible = true;
		}
		for (ll j = 0; j < k; j++)
		{
			ll c;
			cin >> c;
			dp[i][c] = LLONG_MAX;
		}
	}

	if (notPossible) {
		cout << -1 << endl;
		return;
	}

	for (auto &j : dp[0]) {
		j.second = 0;
	}

	for (ll i = 1; i < n; i++)
	{
		for (auto &j : dp[i]) {
			auto it = dp[i - 1].lower_bound(j.first);
			if (it != dp[i - 1].end()) {
				j.second = min(j.second, (*it).second + (*it).first - j.first);
			}
			if (it != dp[i - 1].begin()) {
				it--;
				j.second = min(j.second, (*it).second + j.first - (*it).first);
			}
		}
	}

	ll ans = LLONG_MAX;

	for (auto &j : dp[n - 1]) {
		ans = min(ans, j.second);
	}

	cout << ans << endl;
}

int main() {

	init_code();
	ios_base::sync_with_stdio(false);

	ll T;
	cin >> T;

	while (T--)
	{
		solve();
	}

	return 0;

}