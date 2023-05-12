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
vector<int> v(N);

int solve(int k) {
	int t = (n - k);
	set<int> st;
	for (int i = t + 1; i <= n; i++) {
		st.insert(i);
	}

	for (int i = 0; i < k; i++) {
		if (st.find(v[i]) != st.end()) {
			st.erase(st.find(v[i]));
		}
	}
	if (st.size() == 0) {
		return 1;
	}

	// pVec(st);

	for (int i = k; i < n; i++) {
		if (v[i - k] > t) {
			st.insert(v[i - k]);
		}

		if (st.find(v[i]) != st.end()) {
			st.erase(st.find(v[i]));
		}
		if (st.size() == 0) {
			return 1;
		}
	}
	return 0;
}

void yash()
{
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]] = i;
	}

	// cout << solve(3);
	// return;

	int ans = 0;
	int l = 1, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (solve(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
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