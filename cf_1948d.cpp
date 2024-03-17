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

int n;
string s;

void yash()
{
	cin >> s;

	// int l = 1, r = n, ans = 1;
	// while (l <= r) {
	// 	int mid = (l + r) / 2;

	// 	int flag = 0;
	// 	if (mid % 2 == 0) {
	// 		flag |= solve(mid);
	// 	}
	// 	else {
	// 		flag |= solve(mid + 1);
	// 		flag |= solve(mid - 1);
	// 	}

	// 	if (flag) {
	// 		ans = mid;
	// 		l = mid + 1;
	// 	}
	// 	else {
	// 		r = mid - 1;
	// 	}
	// }


	int ans = 0;
	n = s.size();

	for (int i = 1; i <= n; i++) {
		int x = i;
		int curr = 0;
		int p = 0, q = x;
		int P = p, Q = q;
		while (Q < n) {
			if (curr == i) {
				// ans = max(ans, curr);
				curr = 0;
				break;
			}
			// cout << p << " " << q << '\n';
			if (s[P] == s[Q] || s[P] == '?' || s[Q] == '?') {
				P++; Q++;
				curr++;
			}
			else {
				if (curr == i) {
					// ans = max(ans, curr);
					curr = 0;
					break;
				}

				P++, Q++;
				curr = 0;
			}
		}

		// if (curr == i) {
		// 	// ans = max(ans, curr);
		// 	curr = 0;
		// 	break;
		// }

		curr = 0;
		for (int j = 0; j < n; j++) {
			if (curr == i) {
				ans = max(ans, curr);
				break;
			}
			if (j + i < n) {
				if (s[j] == s[j + i] || s[j] == '?' || s[j + i] == '?') {
					curr++;
					continue;
				}
				curr = 0;
				continue;
			}
			if (curr == i) {
				ans = max(ans, curr);
			}
			curr = 0;
		}
		if (curr == i) {
			ans = max(ans, curr);
		}
	}

	cout << ans * 2 << '\n';
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