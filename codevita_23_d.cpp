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

// shoelace formula

int n;
vector<pair<int, int>> v;
int dp[11][11][(1 << 11)];

int go(int mask, int prev, int taken, int last) {
	if (taken == n - 1) {
		return (v[prev].first + v[last].first) * (v[prev].second - v[last].second);
	}

	int &ans = dp[prev][last][mask];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == last) continue;
		if (!(mask & (1 << i))) {
			ans = max(ans, ((v[prev].first + v[i].first) * (v[prev].second - v[i].second)) + go(mask ^ (1 << i), i, taken + 1, last));
		}
	}

	return ans;
}


// void trace(int mask, int prev, int taken) {
// 	if (taken == n) {
// 		return;
// 	}

// 	int ans = dp[prev][mask];


// 	for (int i = 0; i < n; i++) {
// 		if (!(mask & (1 << i))) {
// 			int curr = ((v[prev].first + v[i].first) * (v[prev].second - v[i].second)) + go(mask ^ (1 << i), i, taken + 1);
// 			if (ans == curr) {
// 				cout << i << "\n";
// 				trace(mask ^ (1 << i), i, taken + 1);
// 				return;
// 			}
// 		}
// 	}
// }


void yash()
{
	cin >> n;
	vector<int> x(n), y(n);
	v.clear();
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		v.push_back({x[i], y[i]});
	}

	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int curr = abs(go(0, i, 0, i) / 2.0);
		// cout << curr << '\n';
		ans = max(ans, curr);
	}
	cout << ans << '\n';

	// cout << polygonArea(v, n) << '\n';
}

signed main()
{
	// init_code();
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	// test
	yash();
	return 0;
}