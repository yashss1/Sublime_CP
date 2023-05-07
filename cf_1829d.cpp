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
const int N = 1e7 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m;
// int dp[N];
int go(int x) {
	if (x == m) {
		return 1;
	}
	if (x % 3 != 0) {
		return 0;
	}

	int c1 = go(x / 3);
	int c2 = go((2 * x / 3));

	return c1 | c2;
}

void yash()
{
	cin >> n >> m;
	int ans = go(n);

	if (ans == 1) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";

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