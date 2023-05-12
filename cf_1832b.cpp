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
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	sort(all(v));

	vector<int> pref(n + 1, 0), suff(n + 2, 0);
	suff[n] = v[n - 1];
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + v[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1)
			suff[i + 1] = suff[i + 2] + v[i];
	}

	// pVec(pref);
	// pVec(suff);

	// pVec(v);
	// cout << sum << '\n';

	// int i = 0, j = n - 1;

	// while (i + 1 < j && k--) {
	// 	int t1 = v[i];
	// 	int t2 = v[i + 1];
	// 	int t3 = v[j];

	// 	if (t1 + t2 < t3) {
	// 		sum -= (t1 + t2);
	// 		i += 2;
	// 	}
	// 	else {
	// 		sum -= t3;
	// 		j--;
	// 	}
	// }

	// cout << sum << '\n';
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int t1 = pref[i * 2];
		int rem = k - i;
		int t2 = suff[n - rem + 1];
		ans = max(ans, sum - (t1 + t2));
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