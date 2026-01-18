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
	vector<int> v(n), res(n + 1, 0);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		res[i + 1] = res[i] + v[i];
		mx = max(mx, v[i]);
		v[i] = mx;
	}

	// pVec(v);

	while (q--) {
		int x;
		cin >> x;
		int l = 0, r = n - 1, ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (x >= v[mid]) {
				ans = res[mid + 1];
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		cout << ans << ' ';
	} cout << '\n';
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