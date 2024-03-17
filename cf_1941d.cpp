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


int n, m, x;
vector<pair<int, char>> v;
vector<vector<int>> dp;

int anTiclock(int a, int b) {
	if (a - b > 0)
		return a - b;
	else
		return a - b + n;
}

int cLock(int a, int b) {
	if (a + b == n)
		return n;
	else
		return (a + b) % n;
}

int go(int idx, int pos) {
	if (idx == m) {
		return pos == x;
	}

	int &ans = dp[idx][pos];
	if (ans != -1) {
		return ans;
	}


	int c1 = 0, c2 = 0;
	if (v[idx].second == '0') { // anti
		int poss = anTiclock(pos, v[idx].first);
		// cout << pos << " " << v[idx].first << " " << poss << '\n';
		c1 = go(idx + 1, poss);

	}
	if (v[idx].second == '1') {
		int poss = cLock(pos, v[idx].first);
		// cout << pos << " " << v[idx].first << " " << poss << '\n';
		c1 = go(idx + 1, poss);

	}
	if (v[idx].second == '?') {
		int poss = anTiclock(pos, v[idx].first);
		// cout << pos << " " << v[idx].first << " " << poss << '\n';
		int poss2 = cLock(pos, v[idx].first);
		c1 = go(idx + 1, poss);
		c2 = go(idx + 1, poss2);
	}

	return ans = c1 | c2;
}

void yash()
{
	cin >> n >> m >> x;
	v.clear();
	for (int i = 0; i < m; i++) {
		int x; char c; cin >> x >> c;
		v.push_back({x, c});
	}
	reverse(all(v));
	dp.assign(m + 1, vector<int>(n + 1, -1));

	int ans = 0;
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		ans += go(0, i);
		if (go(0, i)) {
			res.push_back(i);
		}
	}
	cout << ans << '\n';
	pVec(res);
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