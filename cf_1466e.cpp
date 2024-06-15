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
vector<int> power(61);

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> mp(61, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 60; j++) {
			if ((v[i] & (1ll << j))) {
				mp[j]++;
			}
		}
	}

	// for (auto it : mp) {
	//     cout << it.first << " " << it.second << '\n';
	// }

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int sumAnd = 0, sumOr = 0;
		sumOr += ((n % MOD) * (v[i] % MOD));
		sumOr %= MOD;

		for (int j = 0; j <= 60; j++) {
			if (!(v[i] & (1ll << j))) {
				int res = mp[j];
				if (res <= 0) continue;
				sumOr += ((power[j] % MOD) * (res % MOD));
				sumOr %= MOD;
			}
			else {
				int res = mp[j];
				sumAnd += ((power[j] % MOD) * (res % MOD));
				sumAnd %= MOD;
			}
		}

		ans += ((sumOr % MOD) * (sumAnd % MOD));
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
	for (int i = 0; i <= 60; i++) {
		power[i] = fpow(2ll, i) % MOD;
	}
	test
	yash();
	return 0;
}