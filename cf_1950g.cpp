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
vector<pair<int, int>> v;
vector<vector<int>> dp;

int go(int mask, int prev) {
	if (mask == (pow(2, n) - 1)) {
		return 0;
	}

	int &ans = dp[prev][mask];
	if (ans != -1) {
		return ans;
	}

	ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (!(mask & (1 << i))) {
			// take it as next
			if ((v[prev].first == v[i].first) || (v[prev].second == v[i].second)) {
				ans = min(ans, go(mask ^ (1 << i), i));
			}
			// delete it
			ans = min(ans, 1 + go(mask ^ (1 << i), prev));
		}
	}
	return ans;
}

void yash()
{
	cin >> n;
	v.clear();
	dp.assign(n, vector<int>(pow(2, n), -1));

	vector<pair<string, string>> V;
	map<string, int> A, B;
	int p = 1, q = 1;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		V.push_back({a, b});
		if (A[a] == 0) {
			A[a] = p;
			p++;
		}
		if (B[b] == 0) {
			B[b] = q;
			q++;
		}
	}

	for (int i = 0; i < n; i++) {
		v.push_back({A[V[i].first], B[V[i].second]});
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		ans = min(ans, go(1 << i, i));
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