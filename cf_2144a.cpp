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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = 0, b = 0, c = 0;

			for (int k = 0; k < i; k++) {
				a += v[k];
			}
			for (int k = i; k < j; k++) {
				b += v[k];
			}
			for (int k = j; k < n; k++) {
				c += v[k];
			}
			// if (j + 1 == n) {
			// 	continue;
			// }
			a %= 3;
			b %= 3;
			c %= 3;
			// cout << i << ' ' << j << " -> " << a << " " << b << " " << c << '\n';
			if (a != b && b != c && c != a) {
				cout << i  << " " << j  << '\n';
				return;
			}
			if (a == b && b == c && c == a) {
				cout << i  << " " << j  << '\n';
				return;
			}
		}
	}
	cout << "0 0\n";

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