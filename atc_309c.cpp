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
	vector<pair<int, int>> v;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
		sum += b;
	}

	sort(v.begin(), v.end());

	// cout << sum << '\n';
	// for (auto it : v) {
	// 	cout << it.first << " " << it.second << '\n';
	// }

	if (sum <= k) {
		cout << "1\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		sum -= v[i].second;
		if (sum <= k) {
			cout << v[i].first + 1 << '\n';
			return;
		}
	}
	cout << n + 1 << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}