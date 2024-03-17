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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m), c(k);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];

	}

	int l = 0, r = 1e12;
	int ans = INT_MAX;
	while (l <= r) {
		int fl = 0;
		int mid = (l + r) / 2;
		int flag = 0;

		for (int i = 1; i < n; i++) {
			int A = a[i - 1], B = a[i];
			if (B - A > mid) {
				// cout << a[i] << '\n';
				// flag++;
				if (flag == 0) {
					map<int, int> mp;

					int mn = max(B - mid, A + 1);
					int mx = min(A + mid, B - 1);
					vector<int> res;

					// cout << mx << " " << mn << '\n';

					for (int j = 0; j < m; j++) {
						res.push_back(b[j]);
					}

					sort(res.begin(), res.end());
					// pVec(res);

					for (int j = 0; j < k; j++) {
						// if (c[j] <= mx && c[j] >= mn) {
						// 	// int mnn = mn - c[j];
						// 	// int mxx = mx - c[j];

						// 	if (res[0] + c[j] <= mx) {
						// 		flag++;
						// 		break;
						// 	}
						// }
						int num = mn - c[j];
						int L = 0, R = res.size() - 1;
						int anss = -1;
						while (L <= R) {
							int M = (L + R) / 2;
							if (res[M] >= num) {
								anss = M;
								R = M - 1;
							}
							else {
								L = M + 1;
							}
						}

						if (anss == -1) {

						}
						else if (res[anss] + c[j] <= mx) {
							flag++;
							break;
						}
					}
					if (flag == 0) {
						fl = 1;
						break;
					}

				} else {
					fl = 1;
					break;
				}
			}
		}
		if (fl == 1) {
			l = mid + 1;
		}
		else {
			ans = mid;
			r = mid - 1;
		}
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