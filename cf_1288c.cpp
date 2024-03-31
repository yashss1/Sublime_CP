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

int n, m;
vector<vector<int>> dp;

int go(int idx, int m) {
	if (m < 0) {
		return 0;
	}
	if (m == 0) {
		return 1;
	}
	if (idx == n) {
		return 1;
	}

	int &ans = dp[m][idx];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	ans += go(idx, m - 1);
	ans %= MOD;
	ans += go(idx + 1, m);
	ans %= MOD;

	return ans;
}

void yash()
{
	cin >> n >> m;
	dp.assign(2 * m + 1, vector<int>(n + 1, -1));
	int ans = go(1, 2 * m);
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