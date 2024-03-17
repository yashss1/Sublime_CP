//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
// #define int               long long
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
vector<int> v;
vector<vector<int>> dp;

int go(int idx, int prev) {
	if (idx == n) {
		return prev != 0;
	}

	int &ans = dp[idx][prev];
	if (ans != -1) {
		return ans;
	}

	int c1 = INT_MAX, c2 = INT_MAX;
	if (prev == 0) {
		c1 = go(idx + 1, v[idx]);
	} else {
		c1 = 1 + go(idx + 1, v[idx] ^ prev);
		c2 = 1 + go(idx + 1, v[idx]);
	}
	return ans = min({c1, c2});
}

void yash()
{
	cin >> n;
	v.assign(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	dp.assign(n + 1, vector<int>(8192, -1));

	int ans = go(0, 0);
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