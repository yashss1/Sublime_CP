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

int fpow(int x, int y, int p = MOD) {
	x = x % p; int sum = 1; while (y) {
		if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
	} return sum;
}
int fact[3000007] = {0};
void facto() {
	fact[0] = 1; fact[1] = 1; for (int i = 2; i < 300000; i++)fact[i] = (fact[i - 1] * i) % MOD;
}

int ncr(int n, int r) {
	if (r > n)return 0;
	int res = 1; res = fact[n]; res = (res * (fpow(fact[r], MOD - 2))) % MOD; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}

void yash()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	map<int, int> there, taken;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		there[v[i]]++;
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < min(n, k); i++) {
		taken[v[i]]++;
	}


	int ans = 1;
	for (auto it : taken) {
		// thereCtaken
		ans *= (ncr(there[it.first], it.second));
		ans %= MOD;
	}

	cout << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	facto();
	test
	yash();
	return 0;
}