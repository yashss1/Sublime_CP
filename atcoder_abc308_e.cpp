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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
string s, S = "MEX";
vector<int> v(N);

int calc(int mex) {
	for (int i = 0; i <= 3; i++) {
		if (!((1ll << i) & mex)) {
			return i;
		}
	}
	return 0;
}

int dp[3][9][N];
int go(int idx, int ch, int mex) {
	if (ch == 3) {
		return calc(mex);
	}
	if (idx == n) {
		if (ch == 3) {
			return calc(mex);
		}
		return 0;
	}

	int &ans = dp[ch][mex][idx];
	if (ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0;
	if (S[ch] == s[idx]) {
		c1 = go(idx + 1, ch + 1, ((1ll << v[idx]) | mex));
	}
	c2 = go(idx + 1, ch, mex);

	return ans = c1 + c2;
}

void yash()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> s;
	memset(dp, -1, sizeof(dp));

	int ans = go(0, 0, 0);
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