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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> v(x);
	for (int i = 0; i < x; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	if (n == 4) {
		// square
		if (v.size() == 1) {
			cout << "0\n";
			return;
		}
		if (v.size() == 2) {
			if (abs(v[0] - v[1]) == 2) {
				cout << abs(v[0] - v[1]) << "\n";
				return;
			}
			cout << "0\n";
			return;
		}
		cout << "2\n";
		return;
	}

	int ans = ((v[x - 1] + 2) % n == v[0]);
	for (int i = 1; i < x; i++) {
		if (v[i] - v[i - 1] == 2) {
			ans++;
		}
	}

	int res = ans + max(0ll, x - 2);
	cout << res << "\n";
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