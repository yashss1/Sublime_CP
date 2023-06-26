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
	int n, k, g;
	cin >> n >> k >> g;

	int t = k * g;
	int a = (g / 2) + (g % 2);
	a--;

	int ans, rem;

	if (a != 0) {
		ans = (min(n - 1, t / a)) * (a);
		rem = (t - (ans));
	}
	else {
		ans = 0;
		rem = t;
	}


	// cout << ans << " " << rem << '\n';
	int r = (rem % g);

	ans += (r);

	if (r >= (g / 2)) {
		ans -= g;
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