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
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
string s;

int dp[5][N];
int go(int idx, int i) {
	if (idx == n) {
		return (i == 4);
	}

	int &ans = dp[i][idx];
	if (ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0;
	if (i == 0) {
		if (s[idx] == 'P')
			c1 = go(idx + 1, i + 1);
		c2 = go(idx + 1, i);
	}
	else if (i == 1) {
		if (s[idx] == 'I')
			c1 = go(idx + 1, i + 1);
		c2 = go(idx + 1, i);
	}
	else if (i == 2) {
		if (s[idx] == 'C') {
			c1 = go(idx + 1, i + 1);
		}
	}
	else if (i == 3) {
		if (s[idx] == 'T')
			c1 = go(idx + 1, i + 1);
		c2 = go(idx + 1, i);
	}
	else {
		c1 = go(idx + 1, i);
	}

	return ans = (c1 + c2) % MOD;
}

void yash()
{
	cin >> s;
	n = s.size();
	memset(dp, -1, sizeof(dp));

	int ans = go(0, 0);
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