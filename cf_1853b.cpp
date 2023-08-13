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

bool check(int n, int n1, int k) {
	int prev = n1, prev2 = n;
	k -= 2;
	while (k--) {
		int t = prev2 - prev;
		// cout << prev2 << " " << prev << ' ' << t << "\n";
		if (t > prev) {
			return false;
		}
		prev2 = prev;
		prev = t;
	}
	return true;
}

void yash()
{
	int n, k;
	cin >> n >> k;

	int ans = 0;
	for (int i = (n / 2); i <= n; i++) {
		if (check(n, i, k)) {
			ans++;
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