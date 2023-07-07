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
const int N = 500 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m, k;
vector<vector<int>> v, pre;

int dp[N][N];

int go(int idx, int kk) {
	if (kk < 0) {
		return -1e9;
	}

	if (idx == n) {
		return (k == 0);
	}

	int &ans = dp[idx][kk];
	if (ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0;
	for (int i = 1; i <= min(m, kk); i++) { // segment length
		c1 = max(c1, pre[idx][i] + go(idx + 1, kk - i));
	}

	// no lectures
	c2 = go(idx + 1, kk);

	return ans = max({c1, c2});

}

void yash()
{
	cin >> n >> m >> k;
	v.assign(n, vector<int>(m));
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	// precomputation -> woke up at 5:09am again after 30min of sleep, when it got clicked ;)

	pre.assign(n, vector<int>(m + 1, 0)); // pre[i][j] denotes -> maxSum if taken j length segment from ith row
	for (int i = 0; i < n; i++) {

		vector<int> hsh(m + 1, 0); // prefix sum
		for (int j = 0; j < m; j++) {
			hsh[j + 1]  = hsh[j] + v[i][j];
		}

		for (int kk = 1; kk <= m; kk++) { // making kk sized segments
			int mx = INT_MIN;
			for (int j = kk; j <= m; j++) {
				int currSum = hsh[j] - hsh[j - kk];
				mx = max(mx, currSum);
			}
			pre[i][kk] = mx;
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << i << " -> \n";
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << j << " " <<  pre[i][j] << "\n";
	// 	}
	// }

	int ans = go(0, k);
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