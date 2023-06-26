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

int n, m, q;
vector<pair<int, int>> v;
vector<int> queries;

int solve(int k) {
	vector<int> temp(n + 1, 0);
	for (int i = 0; i <= k; i++) {
		temp[queries[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		temp[i] = temp[i - 1] + temp[i];
	}

	for (int i = 0; i < m; i++) {
		int t = temp[v[i].second] - temp[v[i].first - 1];
		int sz = v[i].second - v[i].first + 1;
		if (t > (sz - t)) {
			return 1;
		}
	}
	return 0;
}

void yash()
{
	cin >> n >> m;
	v.clear();
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v.push_back({a, b});
	}

	cin >> q;
	queries.assign(q, 0);
	for (int i = 0; i < q; i++) {
		cin >> queries[i];
	}

	int l = 0, r = q - 1, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (solve(mid)) {
			ans = mid + 1;
			r = mid - 1;
		}
		else {
			l = mid + 1;
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
