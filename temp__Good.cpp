#include <bits/stdc++.h>
using namespace std;


void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
	init_code();
	int n;
	cin >> n;

	vector<int> v(n);
	int mx = INT_MIN;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	int k;
	cin >> k;

	if (n > k) {
		cout << -1 << endl;
	} else {
		sort(v.begin(), v.end());
		int ans = INT_MAX;
		for (int tankSize = 1; tankSize <= mx; tankSize++) {

			int trips = 0, spill = 0;
			for (int i = 0; i < n; i++) {
				trips += (v[i] / tankSize) + (v[i] % tankSize != 0 ? 1 : 0);
				spill += tankSize - (v[i] % tankSize == 0 ? tankSize : v[i] % tankSize);
			}

			if (trips <= k) {
				ans = min(ans, spill);
			}

		}
		cout << ans << '\n';
	}

	return 0;
}