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
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mn = min(mn, v[i]);
	}
	sort(all(v), greater<int>());

	int l = 0, r = 1e12, ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		int x = 0;
		int fl = 0;

		for (int i = 0; i < n; i++) {
			x++;
			if ((mid / x + (mid % x == 0 ? 0 : 1)) <= v[i]) {
				fl = 1;
				break;
			}
		}

		if (fl) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << ans << "\n";

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