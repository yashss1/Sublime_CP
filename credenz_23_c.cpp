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
string l, r;
int n;
int x, y;

// mask ith bit unset, if even times, else odd times
int dp[2][2][2][200][10];

int go(int idx, int edgeBottom, int edgeTop, int nonZeroTaken, int prev) {
	if (idx == n) {
		return 1;
	}


	int &ans = dp[nonZeroTaken][edgeTop][edgeBottom][idx][prev];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = 0; i < 10; i++) {
		if (edgeTop && i > r[idx] - '0') continue;
		if (edgeBottom && i < l[idx] - '0') continue;

		if (i == prev && nonZeroTaken == 1) continue;

		ans += go(idx + 1, (edgeBottom && i == l[idx] - '0'), (edgeTop && i == r[idx] - '0'), (nonZeroTaken || (i != 0)), i);
		ans %= MOD;
	}

	return ans;
}

void yash()
{
	cin >> l >> r;
	string s(r.size() - l.size(), '0');
	reverse(l.begin(), l.end());
	l += s;
	reverse(l.begin(), l.end());
	n = l.size();

	cin >> y >> x;

	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (i < l[0] - '0') continue;
		if (i > r[0] - '0') continue;

		ans += go(1, (l[0] - '0' == i), (r[0] - '0' == i), (i != 0), i);
		ans %= MOD;
	}

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