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
	int n, k, d;
	cin >> n >> k >> d;

	vector<int> v(n), b(k);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < k; i++) {
		cin >> b[i];
	}

	vector<int> temp = v;

	int curr = 0;
	for (int j = 0; j < n; j++) {
		if (temp[j] == j + 1) {
			curr++;
		}
	}

	int rem = (d - 1);
	curr += (rem / 2);

	int ans = 0;
	ans = max(ans, curr);

	for (int i = 0; i < min({n, d}); i++) {
		for (int j = 0; j < b[i % k]; j++) {
			temp[j]++;
		}

		int curr = 0;
		if (d - i - 1 > 0) {
			for (int j = 0; j < n; j++) {
				if (temp[j] == j + 1) {
					curr++;
				}
			}
		}
		int rem = max(0ll, d - i - 2);
		curr += (rem / 2);

		ans = max(ans, curr);

		// cout << rem << " -> " << curr << '\n';
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