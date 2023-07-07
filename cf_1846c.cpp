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

bool cmp(pair<pair<int, int>, pair<int, int>>&p1, pair<pair<int, int>, pair<int, int>>&p2) {
	if (p1.first.first != p2.first.first) {
		return p1.first.first > p2.first.first;
	}
	// if (p1.first.second != p2.first.second) {
	// 	return p1.first.second < p2.first.second;
	// }
	if (p1.second.first != p2.second.first)  {
		return p1.second.first < p2.second.first;
	}
	return p1.second.second < p2.second.second;
}

void yash()
{
	int n, m, h;
	cin >> n >> m >> h;
	vector<vector<int>> v(n, vector<int>(m));

	// cout << n << " " << m << " " << h << '\n';

	vector<vector<int>> res;
	for (int i = 0; i < n; i++) {
		// cout << i << '\n';
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			temp.push_back(v[i][j]);
		}
		sort(all(temp));
		int sc = 0, totalPnl = 0, fnTime = 0;
		int sm = 0;
		for (int j = 0; j < m; j++) {
			if (sm + temp[j] > h) {
				break;
			}
			totalPnl += sm + temp[j];
			sm += temp[j];
			sc++;
		}
		res.push_back({ -sc, totalPnl, i});
	}

	sort(all(res));

	// for (auto it : res) {
	// 	cout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << '\n';
	// }

	for (int i = 0; i < n; i++) {
		if (res[i][2] == 0)  {
			cout << i + 1 << '\n';
			return;
		}
	}
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