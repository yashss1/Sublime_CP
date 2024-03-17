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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	int mx = 0, mx2 = 0;
	int neg = 0;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (b[i] < 0) {
			neg = 1;
			mx = max(mx, -b[i]);
		}
		else {
			mx2 = max(mx2, b[i]);
		}
	}

	sort(a.begin(), a.end());
	sort(all(b));

	if (mx == mx2) {
		if (abs(a[0]) < abs(a[n - 1])) {
			a.pop_back();
		}
		else {
			reverse(all(a));
			a.pop_back();
			reverse(all(a));
		}
	}

	if (a.size() == n - 1) {
		int ans = b[m - 1] * a[n - 2];
		cout << ans << '\n';
		return;
	}

	if (mx > mx2 || neg == 0) {
		a.pop_back();
	}
	else {
		reverse(all(a));
		a.pop_back();
		reverse(all(a));
	}

	int ans = b[m - 1] * a[n - 2];
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