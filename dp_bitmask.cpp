// DP with Bitmask
// https://codeforces.com/contest/16/problem/E

//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 20;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<vector<double>> v(N, vector<double>(N));
int dp[(1 << N)];

// Probability of moving from previous day to current day
double pMove(int prev_mask, int i) {
	// kill the ith fish

	int k = __builtin_popcount(prev_mask);
	int denominator = k * (k - 1) / 2;

	double moveProbability = 0;
	for (int fish = 0; fish < n; fish++) {
		if ((1 << fish)&prev_mask) {
			moveProbability = v[fish][i];
		}
	}

	return moveProbability / (float)denominator;

}

double go(int mask) {
	// ith bet set -> Fish i is alive

	int alive = __builtin_popcount(mask);
	if (alive == n) {
		return 1;
	}

	double ans = dp[mask];

	if (ans > -0.9) {
		return ans;
	}

	ans = 0;
	for (int fish = 0; fish < n; fish++) {
		if (!(mask & (1 << fish))) {
			// ith fish is dead here, so what is probability it was alive one day before

			int prev_mask = mask ^ (1 << fish);
			double prev_day = go(prev_mask); // make the ith bit 1

			ans += prev_day * pMove(prev_mask, fish);
		}
	}

	dp[mask] = ans;

	return ans;
}

void yash()
{
	cin >> n;
	rep(i, 0, n) {
		rep(j, 0, n) {
			cin >> v[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0) << '\n';

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