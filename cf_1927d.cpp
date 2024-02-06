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
	map<int, vector<int>> mp;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]].push_back(i);
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		if (v[l] != v[r]) {
			cout << l + 1 << " " << r + 1 << '\n';
			continue;
		}

		int num = v[l];

		int L = 0, R = mp[num].size() - 1;
		int curr1 = 0;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (mp[num][mid] >= l) {
				curr1 = mid;
				R = mid - 1;
			}
			else {
				L = mid + 1;
			}
		}

		L = 0, R = mp[num].size() - 1;
		int curr2 = 0;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (mp[num][mid] <= r) {
				curr2 = mid;
				L = mid + 1;
			}
			else {
				R = mid - 1;
			}
		}

		// cout << num << " -> ";
		// pVec(mp[num]);
		// cout << curr1 << " " << curr2 << '\n';

		if (curr2 - curr1 + 1 == (r - l + 1)) {
			cout << "-1 -1\n";
			continue;
		}


		L = curr1, R = curr2;
		int curr3 = 0;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (mp[num][mid] != mid + curr1) {
				curr3 = mid + curr1;
				R = mid - 1;
			}
			else {
				L = mid + 1;
			}
		}

		cout << l + 1 << " " << curr3 + 1 << "\n";
	}
	cout << '\n';
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