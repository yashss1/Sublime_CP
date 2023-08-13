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
	int n, m;
	cin >> n >> m;
	vector<pair<int, map<int, int>>> v;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		int x;
		cin >> x;
		vector<int> temp(x);
		map<int, int> mp;
		for (int j = 0; j < x; j++) {
			cin >> temp[j];
			mp[temp[j]]++;
		}

		v.push_back({p, mp});
	}

	sort(all(v));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			map<int, int> mp1 = v[i].second;
			map<int, int> mp2 = v[j].second;
			int flag = 1;

			for (auto it : mp2) {
				if (mp1[it.first] == 0) {
					flag = 0;
				}
			}

			if (flag == 1) {
				if (mp1.size() > mp2.size()) {
					cout << "Yes\n"; return;
				}
				if (v[j].first > v[i].first) {
					cout << "Yes\n"; return;
				}
			}

		}
	}

	cout << "No\n";
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