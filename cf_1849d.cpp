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
vector<int> v(N);
int dp[3][3][N];

// N givefront loanTakenAlready

int go(int idx, int giveFront, int loanTakenAlready) {
	if (loanTakenAlready > v[idx]) {
		return INT_MAX;
	}
	if (idx == n) {
		return 0;
	}

	int &ans = dp[giveFront][loanTakenAlready][idx];
	if (ans != -1) {
		return ans;
	}

	int curr = v[idx];
	curr -= loanTakenAlready;

	int c1 = 1 + go(idx + 1, curr, 0);
	int c2 = go(idx + 1, 0, 1);
	int c3 = INT_MAX;
	if (giveFront >= 1) {
		c3 = go(idx + 1, curr, 0);
	}

	return ans = min({c1, c2, c3});
}

void yash()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	memset(dp, -1, sizeof(dp));

	int ans = min(1 + go(1, v[0], 0), go(1, 0, 1));
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