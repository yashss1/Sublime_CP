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


	int a = 1, d = 2;
	while (n > 0) {
		// cout << "N " << n << " " << a << '\n';
		if (k <= ((n  + 1) / 2)) {
			int ans = a + ((k - 1) * d);
			cout << ans << '\n';
			return;
		}
		k -= ((n  + 1) / 2);
		n -= ((n  + 1) / 2);
		a *= 2;
		d *= 2;
	}
	assert(false);
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