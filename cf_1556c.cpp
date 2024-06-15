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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// int sum1 = 0;
	// for (int i = 0; i < n; i++) {
	// 	if (i % 2 == 0) {
	// 		sum1 += v[i];
	// 	}
	// 	else {
	// 		sum1 -= v[i];
	// 	}

	// 	cout << sum1 << " ";
	// } cout << '\n';

	int ans = 0;
	int sum = 0, prev = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			sum += v[i];
		} else sum -= v[i];

		if (i % 2 == 0) {
			int p = prev, q = sum;
			// cout << "\n\n" << i << '\n';
			// cout << p << " " << q << "\n";

			int newSum = sum, newPrev = sum;
			for (int j = i + 1; j < n; j++) {
				if (j % 2 == 0) {
					newSum += v[j];
				} else newSum -= v[j];

				if (j % 2 == 1) {
					if (j == i + 1) {
						newPrev--;
					}

					int r = newPrev, l = newSum;
					// if (p > q) swap(p, q);
					// if (l > r) swap(l, r);
					// cout << j << " " << "l r "  << l << " " << r << " | " << "p q " << p << " " << q << "\n";
					int R = min(max(p, q), max(l, r));
					int L = max(min(p, q), min(l, r));

					// cout << "L R " << L << " " << R << " -> " << (R - L + 1) << "\n";
					ans += max(0ll, R - L + 1);
				}

				newPrev = newSum;
				q = min(q, newSum);
				if (prev > q) {
					break;
				}
				if (p > q) p = q;
			}
		}

		prev = sum;
	}

	cout << ans << '\n';


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