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
Remove min numbers from array such that, diff of (min * 2 > max)

INPUT:
5
22 5 4 7 15

OUTPUT:
2
*/
int go(int i, int j, vector<int> &v, map<int, int> &mp, vector<vector<int>> &dp) {
	if (i >= j) {
		return 0;
	}

	int &ans = dp[i][j];
	if (ans != -1) {
		return ans;
	}

	int c1 = INT_MAX, c2 = INT_MAX;
	if (v[i] * 2 > v[j]) {
		c1 = 0;
	}
	else {
		c1 = mp[v[i]] + go(i + 1, j, v, mp, dp);
		c2 = mp[v[j]] + go(i, j - 1, v, mp, dp);
	}

	return ans = min({c1, c2});
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mp[a]++;
		if (mp[a] == 1) {
			v.push_back(a);
		}
	}
	sort(v.begin(), v.end());

	n = v.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	int ans = go(0, n - 1, v, mp, dp);
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