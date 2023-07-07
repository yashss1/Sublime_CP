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

	// int t = (n / (k + 1));
	// if (n % (k + 1) != 0) {
	// 	t++;
	// }

	// int x = (t / 3);
	// int ans = 6 * x;

	// x = t % 3;
	// for (int i = 1; i <= x; i++) {
	// 	ans += i;
	// }

	// cout << ans << '\n';

	int ans = 0;

	int y = (k + 2 + ((k + 1) / 2) - 1);

	int t = (n / (y));
	ans += (t * 3);
	if (n % y == 0) {
		cout << ans << '\n';
		return;
	}

	int x = (n % y);
	if (x >= (k + 2)) {
		ans += 3;
	}
	else {
		ans++;
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