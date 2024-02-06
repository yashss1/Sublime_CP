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

	int l = 1;
	int r = n;
	int ans;

	while (r >= l) {
		int m = (r + l) / 2;
		if (m * k <= n) {
			ans = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	for (int i = 0; i < k; ++i) {
		std::cout << (i + 1) * ans << " ";
	}
	std::cout << std::endl;
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