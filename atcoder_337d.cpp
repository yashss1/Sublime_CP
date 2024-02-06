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
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			v[i][j] = s[j];
		}
	}


	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		vector<int> O(m + 1, 0), D(m + 1, 0);
		vector<char> row = v[i];

		for (int j = 0; j < m; j++) {
			O[j + 1] += O[j] + (row[j] == 'o');
		}
		for (int j = 0; j < m; j++) {
			D[j + 1] += D[j] + (row[j] == '.');
		}
		for (int j = k; j <= m; j++) {
			int prev = (j - k);
			int os = O[j] - O[prev];
			int ds = D[j] - D[prev];

			if (os + ds == k) {
				ans = min(ans, ds);
			}
		}
	}


	for (int i = 0; i < m; i++) {
		vector<int> O(n + 1, 0), D(n + 1, 0);
		vector<char> col;
		for (int j = 0; j < n; j++) {
			col.push_back(v[j][i]);
		}

		for (int j = 0; j < n; j++) {
			O[j + 1] += O[j] + (col[j] == 'o');
		}
		for (int j = 0; j < n; j++) {
			D[j + 1] += D[j] + (col[j] == '.');
		}
		for (int j = k; j <= n; j++) {
			int prev = (j - k);
			int os = O[j] - O[prev];
			int ds = D[j] - D[prev];

			if (os + ds == k) {
				ans = min(ans, ds);
			}
		}
	}

	if (ans == INT_MAX) {
		cout << "-1\n";
		return;
	}

	cout << ans << '\n';
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