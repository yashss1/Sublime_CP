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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int i = 0, j = n - 1, flag = 0;
	int ans = 0;
	while (i <= j) {
		if (i == j) {
			if (v[i] <= k) {
				ans++;
			}
			break;
		}
		if (v[i] <= v[j]) {
			int want;
			if (flag == 0) {
				want = (2 * v[i] - 1);
				if (k < want) {
					break;
				}
				k -= want;
				v[j] -= (want - v[i]);
			}
			else {
				want = 2 * v[i];
				if (k < want) {
					break;
				}
				k -= want;
				v[j] -= (want - v[i]);
			}
			i++;
			if (v[j] == 0) {
				ans++;
				j--;
			}

			if (want % 2 != 0) flag ^= 1;
		}
		else {
			int want;
			if (flag == 1) {
				want = (2 * v[j] - 1);
				if (k < want) {
					break;
				}
				k -= want;
				v[i] -= (want - v[j]);
			}
			else {
				want = 2 * v[j];
				if (k < want) {
					break;
				}
				k -= want;
				v[i] -= (want - v[j]);
			}
			j--;
			if (v[i] == 0) {
				ans++;
				i++;
			}
			if (want % 2 != 0) flag ^= 1;
		}
		// flag ^= 1;
		// cout << i << " " << j << " | " << v[i] << " " << v[j] << " | " << flag << '\n';
		// cout << k << '\n';
		ans++;
		continue;

		int mn = min(v[i], v[j]);
		if (k - mn < 0) {
			break;
		}
		k -= mn;
		if (i == j) {
			ans++;
			break;
		}

		if (flag == 0) {
			if (v[i] == mn) {
				v[j] -= (v[i] - 1);
			}
			else {
				v[j] -= v[i];
			}
			i++;
		}
		else {
			if (v[j] == mn) {
				v[i] -= (v[j] - 1);
			}
			else {
				v[i] -= v[j];
			}
			j--;
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