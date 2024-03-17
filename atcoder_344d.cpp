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
string s;
vector<vector<string>> v;

vector<vector<int>> dp;
int go(int idx, int stringIdx) {
	if (stringIdx == m) {
		return 0;
	}
	if (idx == n) {
		return INT_MAX;
	}

	int &ans = dp[idx][stringIdx];
	if (ans != -1) {
		return ans;
	}

	ans = INT_MAX;
	for (int i = 0; i < v[idx].size(); i++) {
		int p = stringIdx, q = 0;
		while ((v[idx][i][q] == s[p]) && p < m && q < v[idx][i].size()) {
			p++, q++;
		}
		if (q == v[idx][i].size()) {
			ans = min(ans, 1 + go(idx + 1, stringIdx + v[idx][i].size()));
		}
	}
	ans = min(ans, go(idx + 1, stringIdx));
	return ans;
}

void yash()
{
	cin >> s;
	cin >> n;
	m = s.size();

	v.resize(n + 1);
	dp.assign(n + 1, vector<int>(m + 1, -1));
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			string y;
			cin >> y;
			v[i].push_back(y);
		}
		// pVec(v[i]);
	}

	int ans = go(0, 0);
	if (ans >= INT_MAX) {
		ans = -1;
	}
	cout << ans << "\n";
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