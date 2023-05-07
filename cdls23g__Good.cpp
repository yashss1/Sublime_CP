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
const int N = 1e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, k;
vector<int> v[N];

int dp[N][N];

int go(int idx, int prev) {
	if (idx == n) {
		return 0;
	}

	int &ans = dp[idx - 1][prev];
	if (ans != -1) {
		return ans;
	}

	ans = INT_MAX;

	for (int i = 0; i < v[idx].size(); i++) {
		ans = min(ans, abs(v[idx - 1][prev] - v[idx][i]) + go(idx + 1, i));
	}

	return ans;
}

void yash()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v[i].clear();
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			v[i].push_back(a);
		}
		sort(all(v[i]));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size() + 1; j++) {
			dp[i][j] = -1;
		}
	}

	int ans = 1e18;
	for (int i = 0; i < v[0].size(); i++) {
		ans = min(ans, go(1, i));
	}

	if (ans == 1e18) {
		cout << "-1\n";
		return;
	}
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