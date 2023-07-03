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
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int x1 = abs(c - a), y1 = abs(d - b);
	int x2 = abs(e - a), y2 = abs(f - b);

	// cout << x1 << " " << y1 << ' ' << x2 << " " << y2 << '\n';
	int x = 0, y = 0;
	if ((c - a < 0 && e - a < 0) || (c - a > 0 && e - a > 0)) {
		x = 1;
	}
	if ((d - b < 0 && f - b < 0) || (d - b > 0 && f - b > 0)) {
		y = 1;
	}

	int ans = (x == 0) ? 0 : min(x1, x2);
	ans += (y == 0) ? 0 : min(y1, y2);
	cout << ans + 1 << '\n';
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