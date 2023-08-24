//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               unsigned long long
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
	int n;
	cin >> n;
	// for (int i = 1; i <= 50; i++) {
	// 	int t = (i *  (i - 1) / 2);

	// 	cout << t << "\n";
	// }
	int l = 0, r = 1e11, ans = 0, tt;
	while (l <= r) {
		int mid = (l + r) / 2;
		// cout << mid << "\n";

		int t = (mid * (mid - 1) / 2);
		if (t <= n) {
			ans = mid;
			tt = t;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	// cout << ans << " " << tt << '\n';
	// int t = (ans + 1) * ans / 2;
	// cout << t << '\n';
	cout << ans + (n - tt) << "\n";
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