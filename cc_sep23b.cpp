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
	int a, b;
	cin >> a >> b;

	int res = ((a / 2) * 5);
	if (b > res) {
		int ans = 5;
		int rem = (b - (res));
		int t = a;
		ans += ((rem / t) + (rem % t == 0 ? 0 : 1));
		cout << ans << '\n';
	}
	else {
		int t = (a / 2);
		cout << (b / t) + (b % t == 0 ? 0 : 1) << '\n';
	}

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