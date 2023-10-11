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
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<int> hsh(n + 1, 0);
	for (int i = 0; i < n; i++) {
		hsh[i + 1] = hsh[i] + a[i];
	}

	int prev = 0;
	vector<pair<int, int>> temp;
	for (int i = 1; i < n; i++) {
		if (b[i - 1] % b[i] != 0) {
			temp.push_back({prev, i - 1});
			prev = i;
		}
	}
	temp.push_back({prev, n - 1});


	int ans = 0;
	for (auto it : temp) {
		for (int i = it.first; i <= it.second; i++) {

			int l = 0, r = it.second - it.first + 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (i + mid > it.second + 1) {
					r = mid - 1;
					continue;
				}
				int curr = hsh[i + mid] - hsh[i];
				// cout << it.first << " " << it.second << " " << i << " " << mid << " -> " << curr << "\n";

				if (curr <= x) {
					l = mid + 1;
					ans = max(ans, mid);
				}
				else {
					r = mid - 1;
				}
			}

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