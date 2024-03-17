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

	vector<pair<int, int>> ans;

	int t = 20000;
	while (t--) {
		for (int i = 0; i + 1 < n; i += 2) {
			if (v[i] > v[i + 1]) {
				ans.push_back({i, i + 1});
				swap(v[i], v[i + 1]);
			}
		}
		for (int i = 1; i + 1 < n; i += 2) {
			if (v[i] > v[i + 1]) {
				ans.push_back({i, i + 1});
				swap(v[i], v[i + 1]);
			}
		}
		vector<int> temp = v;
		sort(temp.begin(), temp.end());
		if (temp == v) {
			break;
		}
	}

	for (auto it : ans) {
		cout << it.first + 1 << " " << it.second + 1 << '\n';
	}
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