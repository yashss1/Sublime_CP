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

int mod_add(int a, int b, int m) {
	a = a % m; b = b % m;
	return (((a + b) % m) + m) % m;
}

// 0 55 31 18 16 1 0 0 0 0

void yash()
{
	int n, q;
	cin >> n >> q;
	vector<int> ans(n, 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r; i++) {
			int x = (i - l + 1);
			ans[i - 1] = mod_add(ans[i - 1], (x * (x + 1) * (x + 2) / 6ll), MOD);
		}
	}

	pVec(ans);
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}