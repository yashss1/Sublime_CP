//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int                long long
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

	int l = 0, r = 2e18;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			int a, b, c;
			cin >> a >> b >> c;
			int mx = ((c - 1) * (a - b)) + a;
			int mn = mx - (a - b) + 1;
			if (c == 1) {
				mn = 1, mx = a;
			}

			// cout << i << " -> " << mn << " " << mx << " | " << l << " " << r << "\n";

			if ((r < mn || mx < l) && (i != 0)) {
				// ans.push_back(0);
				cout << "0 ";
				continue;
			}

			// cout << i << " " << a << " " << b << " " << c << '\n';

			l = max(l, mn);
			r = min(r, mx);
			// ans.push_back(1);
			cout << "1 ";
		}
		else {
			int a, b;
			cin >> a >> b;

			// AP
			int A = a, D = (a - b);
			// find tn greater than equal to l and r

			int idx1 = 0;
			int L = 1, R = 1e9;
			while (L <= R) {
				int mid = L + ((R - L) / 2);
				int tn = (A + ((mid - 1) * D));
				if (tn >= l) {
					idx1 = mid;
					R = mid - 1;
				}
				else {
					L = mid + 1;
				}
			}

			int ans1 = max(1ll, (l - b - 1) / (a - b) + 1) , ans2 = max(1ll, (r - b - 1) / (a - b) + 1);

			// cout << i << " -> " << a << " " << b << " | " << l << " " << r << " | " << idx1 << " " << idx2 << '\n';
			// cout << A << " " << D << '\n';
			// int tn = (A + (idx1 - 1) * D);
			if (ans1 == ans2) {
				// ans.push_back(idx1);
				cout << ans1 << " ";
			}
			else {
				// ans.push_back(-1);
				cout << "-1 ";
			}
		}
	}

	// pVec(ans);
	cout << "\n";
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