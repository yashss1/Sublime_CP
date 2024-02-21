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
	int n, m, x, y, l;
	cin >> n >> m >> x >> y >> l;

	int right = (m - y) / l;
	int left = (y - 1) / l;
	int up = (x - 1) / l;
	int down = (n - x) / l;

	// cout << left << " " << right << " " << up  << " " << down << '\n';

	int ans = 0;
	ans += (right);
	ans += (left);
	ans += (up);
	ans += (down);

	ans += ((down * right));
	ans += ((down * left));
	ans += ((up * left));
	ans += ((up * right));

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