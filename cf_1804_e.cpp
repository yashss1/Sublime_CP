// YashS
#include <bits/stdc++.h>
using namespace std;
#define test  \
	int T;    \
	cin >> T; \
	while (T--)
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pVec(v)           \
	for (auto e : v)      \
		cout << e << " "; \
	cout << "\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int ask(int n, int l, int r) {
	cout << "? " << n << " ";
	for (int i = l; i <= r; i++) {
		cout << i + 1 << " ";
	}
	cout << endl;
	int t;
	cin >> t;
	return t;
}

void ans(int n) {
	cout << "! " << n << endl;
}

void yash() {
	int n;
	cin >> n;
	vector<int> v(n), hsh(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		hsh[i + 1] = hsh[i] + v[i];
	}

	int l = 0, r = n - 1, res = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;

		int t1 = ask((mid - l + 1), l, mid);
		int w1 = (hsh[mid + 1] - hsh[l]);
		if (t1 > w1) {
			res = mid;
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	ans(res + 1);
}

signed main() {
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test 
	yash();
	return 0;
}