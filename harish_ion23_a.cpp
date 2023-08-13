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

/*
2
5 250
175 133 109 210 97
200 125 128 228 133
4 30
1 2 4 6
5 3 5 6
*/

int dp[102][30001];
int go(int idx, int saving, int n, vector<int>&a, vector<int>&b) {
	if (idx == n) {
		return 0;
	}

	int &ans = dp[idx][saving];
	if (ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0;
	if (saving >= a[idx] && a[idx] <= b[idx]) {
		c1 = (b[idx] - a[idx]) + go(idx + 1, saving - a[idx], n, a, b);
	}
	c2 = go(idx + 1, saving, n, a, b);

	return ans = max({c1, c2});
}

void yash()
{
	int n, s;
	cin >> n >> s;
	vector<int> a(n), b(n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}


	int ans = go(0, s, n, a, b);
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