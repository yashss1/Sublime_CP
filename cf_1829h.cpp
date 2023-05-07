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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, k;
vector<int> v(N);
vector<int> temp;

int mod_add(int a, int b, int m) {
	a = a % m; b = b % m;
	return (((a + b) % m) + m) % m;
}

void go(int idx, int kk, int prt) {
	if (idx == 7) {
		return;
	}
	if (kk == k) {
		temp.push_back(prt);
		return;
	}

	go(idx + 1, kk + 1, prt + pow(2ll, idx));
	go(idx + 1, kk, prt);

}

int dp[128][N];
int go1(int idx, int want) {
	if (idx == n) {
		// cout << want << '\n';
		int p =  __builtin_popcount(want);
		return (p == k);
	}

	int &ans = dp[want][idx];
	if (ans != -1) {
		return ans;
	}

	int c1 = go1(idx + 1, want & v[idx]);
	int c2 = go1(idx + 1, want);

	return ans = mod_add(c1, c2, MOD);
}

void yash()
{
	cin >> n >> k;
	temp.clear();
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < 128; i++) {
		for (int j = 0; j <= n + 2; j++) {
			dp[i][j] = -1;
		}
	}
	int ans = go1(0,  ((1ll << 7ll) - 1));
	ans %= MOD;
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