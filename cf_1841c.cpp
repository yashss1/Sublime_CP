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
string s;
vector<int> pref;
vector<vector<vector<int>>> dp;

int go(int idx, int taken, int mx) {
	if (idx == n) {
		return 0;
	}
	int &ans = dp[taken][mx][idx];
	if (ans != -1) {
		return ans;
	}

	ans = INT_MIN;
	if (mx <= s[idx] - 'A') {
		ans = max(ans, (int)pow(10ll, s[idx] - 'A') + go(idx + 1, taken, s[idx] - 'A'));
	}
	else {
		ans = max(ans, -(int)pow(10ll, s[idx] - 'A') + go(idx + 1, taken, mx));
	}
	if (taken == 0) {
		for (int i = mx; i < 5; i++) {
			ans = max(ans, (int)pow(10ll, i) + go(idx + 1, 1, i));
		}
	}
	return ans;
}

void yash()
{
	cin >> s;
	n = s.size();
	reverse(s.begin(), s.end());
	pref.assign(n + 1, 0);

	for (int i = 0; i < n; i++) {
		pref[i + 1] = max((s[i] - 'A') + 1ll, pref[i]);
	}

	dp.assign(2, vector<vector<int>>(6, vector<int>(n + 1, -1)));
	int ans = go(0, 0, 0);
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