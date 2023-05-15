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
const int N = 1e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int mod_add(int a, int b, int m) {
	a = a % m; b = b % m;
	return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int dp[N];

void yash()
{
	int n;
	cin >> n;

	int ans = dp[n];
	cout << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ans = 6;
	int x = 6;
	int k = 0;
	memset(dp, -1, sizeof(dp));
	dp[1] = 6;
	dp[0] = 0;
	for (int i = 2; i < N; i++) {
		ans = mod_add(ans, mod_add(x, mod_mul(x, 3ll, MOD), MOD), MOD);
		ans = mod_sub(ans, k, MOD);
		k += 6ll;
		k %= MOD;
		x += 6ll;
		x %= MOD;
		// cout << ans << ' ';
		dp[i] = ans;
	}
	test
	yash();
	return 0;
}