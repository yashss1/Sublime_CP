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
int N = 1e2 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int w, f, n;
vector<int> v(N);

int solve(int mid) {
	int water = 0, fire = 0;
	for (int i = 0; i < n; i++) {
		if (water >= v[i]) {
			water -= v[i];
			continue;
		}
		if (fire >= v[i]) {
			fire -= v[i];
			continue;
		}

		int t1 = ((v[i] - water) / w) + ((v[i] - water) % w == 0 ? 0 : 1);
		int t2 = ((v[i] - fire) / f) + ((v[i] - fire) % f == 0 ? 0 : 1);
		// cout << t1 << " " << t2 << '\n';
		if (t1 <= t2) {
			// cout << "w\n";
			water += (w * t1);
			fire += (f * t1);
			mid -= t1;
			if (water >= v[i]) {
				water -= v[i];
				continue;
			}
			if (fire >= v[i]) {
				fire -= v[i];
				continue;
			}
			// assert(false);
		}
		else {
			// cout << "f\n";
			water += (w * t2);
			fire += (f * t2);
			mid -= t2;
			if (water >= v[i]) {
				water -= v[i];
				continue;
			}
			if (fire >= v[i]) {
				fire -= v[i];
				continue;
			}
			// assert(false);
		}
	}

	return (mid >= 0);
}

void yash()
{
	cin >> w >> f;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (w > f) swap(w, f);

	int l = 0, r = 1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (solve(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	// cout << ans << '\n';

	vector<int> hsh(sum + 1, 0);
	hsh[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= 0; j--) {
			if (hsh[j]) {
				hsh[j + v[i]] = 1;
			}
		}
		// pVec(hsh);
	}

	// pVec(hsh);
	ans = INT_MAX;
	for (int i = 0; i <= sum; i++) {
		if (hsh[i] == 0) continue;

		int t1 = ((i) / w) + ((i) % w == 0 ? 0 : 1);
		int t2 = ((sum - i) / f) + ((sum - i) % f == 0 ? 0 : 1);

		int curr = max(t1, t2);
		ans = min(ans, curr);
	}
	cout << ans << '\n';

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