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

vector<int> pows;
void solve() {
	int x = 1;
	for (int i = 0; i < 31; i++) {
		pows.push_back(x);
		x *= 2;
	}
}

int n;
vector<vector<int>> dp;

int go(int idx, int i) {
	if (idx == 0) {
		return 1;
	}
	if (idx < 0 || (i >= 31)) {
		return 0;
	}

	int &ans = dp[i][idx];
	if (ans != -1) {
		return ans;
	}

	int c1 = go(idx - pows[i], i);
	int c2 = go(idx, i + 1);

	return ans = (c1 + c2) % MOD;
}

void yash()
{
	cin >> n;
	dp.assign(32, vector<int>(n + 3, -1));
	int ans = go(n, 0);
	cout << ans << '\n';
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	// test
	yash();
	return 0;
}