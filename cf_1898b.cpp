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

/*
1 4 4 3 5 13 6

6, 4 3, 3 2, 2 1,


17/6 = 3
5 6 6

1 6 6

3 5 5
4 4 5
*/

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int mx = v[n - 1], ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		int t = v[i] % mx;
		int mul = (v[i] / mx) + (t == 0 ? 0 : 1);
		int temp = v[i] / mul;

		ans += (mul - 1);

		mx = temp;
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