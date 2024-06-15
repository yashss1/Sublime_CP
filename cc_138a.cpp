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
	int x, y;
	cin >> x >> y;
	int t = x * 10;
	int a = t - (10 * y);
	int b = y - 100;

	int temp = a / b;
	// if (temp == 0 || temp < 0) {
	// 	cout << "1\n";
	// 	return;
	// }
	// cout << temp << '\n';

	int l = 1, r = 1e12, ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		int n = (y * (10 + mid)) - x * 10;
		if (n <= (100 * mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << "\n";
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