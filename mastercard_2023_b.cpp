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
2
5
1 3 4 1 3
3 5 1 9 7
1 1 1 2 0
4 3 1 7 9
32 1 4 6 8
4
2 3 1 6 4
2 2 9 0 1
3 1 2 4 6
3 2 1 7 9

ans
59
8
*/

void yash()
{
	int n;
	cin >> n;
	int prev = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			int a; cin >> a;
			sum += a;
		}
		if (i == 0) {
			prev = sum;
			continue;
		}
		ans += max(0ll, sum - prev);
		prev = sum;
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