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
const int N = 1e4 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<pair<int, int>> v;

double solve(int x, int y, int a, int b) {
	double t = sqrt((x - a) * (x - a) + (y - b) * (y - b));
	return (double)t;
}

pair<int, double> go(int idx) {
	if (idx == n - 1) {
		return {0, 0};
	}

	pair<int, double> temp = go(idx + 1);
	temp.second += (double)solve(v[idx].first, v[idx].second, v[idx + 1].first, v[idx + 1].second);

	int skipped = 1;
	for (int i = idx + 2; i <= n - 1; i++) {
		pair<int, double> curr = go(i);
		curr.first += skipped;
		curr.second += solve(v[idx].first, v[idx].second, v[i].first, v[i].second);

		double totalCost1 = (curr.first == 0 ? 0 : pow(2, curr.first - 1)) + curr.second;
		double totalCost2 = (temp.first == 0 ? 0 : pow(2, temp.first - 1)) + temp.second;

		if (totalCost1 < totalCost2) {
			temp = curr;
		}

		skipped++;
	}

	return temp;
}


double dp[20][N];
int vis[20][N];
double go2(int idx, int skip) {
	if (skip > 18) return INT_MAX;
	if (idx == n - 1) {
		if (skip == 0) {
			return 0;
		}
		return pow(2ll, skip - 1);
	}

	double &ans = dp[skip][idx];
	if (vis[skip][idx] != 0) {
		return ans;
	}
	int skipped = 0;
	ans = INT_MAX;
	for (int i = idx + 1; i < min(idx + 18, n); i++) {
		double temp = solve(v[idx].first, v[idx].second, v[i].first, v[i].second) + go2(i, skip + skipped);
		if (ans > temp) {
			ans = temp;
		}
		skipped++;
	}
	vis[skip][idx] = 1;
	return ans;
}
void yash()
{
	cin >> n;
	v.clear();
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	// cout << solve(v[0].first, v[0].second, v[1].first, v[1].second) << '\n';
	// pair<int, double> ans = go(0);
	// cout << ans.first << " " << ans.second << '\n';
	// double anss = ans.first + ans.second;


	double anss = go2(0, 0);
	cout << fixed << setprecision(9) << anss << '\n';
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