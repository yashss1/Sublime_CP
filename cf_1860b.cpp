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
	int m, k, a, b;
	cin >> m >> k >> a >> b;

	if (a >= m) {
		cout << "0\n"; return;
	}

	int t = (m - (a + (b * k)));
	if (t > 0) {
		int res = (t / k) + (t % k);
		if (k - (t % k) <= a) {
			res = min(res, (t / k) + 1);
		}
		cout << res << '\n';
		return;
	}

	t = (m / k);
	int rem = (m % k);

	int gave = m - (min(t, b) * k);
	if (gave <= a) {
		cout << "0\n"; return;
	}

	rem = (gave - a);

	if (m % k > a) {
		cout << (m % k) - a << "\n";
		return;
	}
	cout << "0\n"; return;

	int tt = (rem / k);
	int remm = (rem % k);
	if (remm == 0) {
		cout << tt << "\n";
		return;
	}

	int yash = k - remm;

	int res = remm;
	if (yash <= a) {
		res = 1;
	}
	int ans = res + tt;
	cout << min(ans, rem) << '\n';
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