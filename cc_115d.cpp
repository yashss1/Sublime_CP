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

void yash()
{
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += v[i];
	}

	int originalLast = v[n - 1];
	v[n - 1] = v[n - 1] - sum;

	int ans = 0;
	for (auto it : v) {
		ans += max(it, 0ll);
	}

	pVec(v);
	cout << ans << '\n';

	while (q--) {
		int x, y;
		cin >> x >> y;

		int prev = v[x - 1];

		if (x - 1 == n - 1) {
			ans -= v[n - 1];

			v[n - 1] -= originalLast;
			v[n - 1] += y;
			ans += y;


			if (v[n - 1] > 0) ans += v[n - 1];

			pVec(v);
			cout << ans << '\n';

			originalLast = y;
			continue;
		}
		else {
			v[x - 1] = y;
		}

		ans -= prev;
		ans += y;

		if (v[n - 1] > 0) {
			ans -= v[n - 1];
		}

		v[n - 1] += prev;
		v[n - 1] -= y;

		if (v[n - 1] > 0) {
			ans += v[n - 1];
		}

		pVec(v);

		cout << ans << '\n';
	}

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