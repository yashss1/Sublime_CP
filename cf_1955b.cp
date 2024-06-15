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
	int n, c, d;
	cin >> n >> c >> d;
	vector<int> v(n * n);
	map<int, int> mp;
	for (int i = 0; i < (n * n); i++) {
		cin >> v[i];
		mp[v[i]]++;
	}

	sort(all(v));
	// pVec(v);

	vector<vector<int>> ans(n, vector<int>(n));

	int prev = v[0];
	ans[0][0] = v[0];
	mp[prev]--;
	for (int i = 1; i < n; i++) {
		// cout << i << '\n';
		ans[i][0] = prev + c;
		// cout << ans[0][i] << '\n';
		prev = ans[i][0];
		mp[ans[i][0]]--;
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << ans[i][j] << " ";
	// 	} cout << '\n';
	// }

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			ans[i][j] = ans[i][j - 1] + d;
			mp[ans[i][j]]--;
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << ans[i][j] << " ";
	// 	} cout << '\n';
	// }

	for (auto it : mp) {
		if (it.second != 0) {
			cout << "NO\n"; return;
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