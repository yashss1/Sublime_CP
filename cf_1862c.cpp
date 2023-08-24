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
	vector<int> res(n);

	vector<int> ans(n);
	// if (v[0] == n) {
	// 	cout << "YES\n";
	// 	return;
	// }
	// cout << "NO\n";
	// reverse(all(v));
	// int k = 1;
	// ans[0] = n;
	// for (int i = 1; i < n; i++) {
	// 	int t = max(v[i], n - i);
	// 	int diff = v[i - 1] - v[i];
	// 	for (int j = 0; j < (diff); j++) {
	// 		ans[k++] = t;
	// 		if (k >= n) {
	// 			cout << "NO\n";
	// 			return;
	// 		}
	// 	}
	// }
	// pVec(ans);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (v[i] <= n) {
			mp[v[i]]++;
			continue;
		}
		cout << "NO\n";
		return;
	}

	for (int i = n - 1; i >= 1; i--) {
		mp[i] += mp[i + 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (mp[i + 1] != v[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";

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