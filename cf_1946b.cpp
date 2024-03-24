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

void yash()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	int summ = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		summ += v[i];
	}

	int sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		res = max(res, sum);
		if (sum < 0) {
			sum = 0;
		}
	}

	// cout << res << '\n';

	int rem = summ - res;

	int ans = res;
	int temp = res;
	// cout << ans << '\n';

	for (int i = 0; i < k; i++) {
		// cout << temp << '\n';
		ans += (temp);
		ans %= MOD;
		temp *= 2;
		temp %= MOD;
	}


	int anss = (ans + rem + MOD) % MOD;
	anss += MOD;
	anss %= MOD;
	// cout << ans << ' ' << rem << " ";

	cout << anss << '\n';

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