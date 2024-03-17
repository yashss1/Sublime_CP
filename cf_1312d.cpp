//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define ll                long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 998244353;
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int fpow(int x, int y, int p = MOD) {
	x = x % p; int sum = 1; while (y) {
		if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
	} return sum;
}
ll fact[N] = {0};
void facto() {
	fact[0] = 1; fact[1] = 1; for (int i = 2; i < N; i++)fact[i] = (fact[i - 1] * i) % MOD;
}

ll ncr(ll n, ll r) {
	if (r > n)return 0;
	ll res = 1; res = fact[n]; res = (res * (fpow(fact[r], MOD - 2))) % MOD; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}
ll npr(ll n, ll r) {
	if (r > n)return 0;
	ll res = 1; res = fact[n]; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}

void yash()
{

	int n, m;
	cin >> n >> m;


	int ans = ncr(m, n - 1); // take only n - 1, as 1 is common
	ans *= (n - 2); // you can take any n - 2 remaming number as duplicate too
	ans %= MOD;

	int res = 0;

	for (int i = 1; i <= n - 2; i++) {
		// i numbers on left
		// duplicate number will be on either side.
		// chose from n - 2 as 1 is maximum (no option for this), and other is repeated.
		int curr = ncr(n - 3, i - 1) % MOD;
		res += curr;
		res %= MOD;
	}
	// cout << ans << " " << res << '\n';
	int anss = (ans * (res % MOD)) % MOD;
	cout << anss << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	facto();
	// test
	yash();
	return 0;
}