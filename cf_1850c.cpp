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
	vector<pair<int, int>> v(n);
	set<pair<int, int>> st;
	map<pair<int , int>, int> mp2;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		if ((v[i].first <= 0 && v[i].second <= 0) || (v[i].first > 0 && v[i].second > 0)) {
			st.insert({abs(v[i].first), abs(v[i].second)});
			mp2[ {abs(v[i].first), abs(v[i].second)}]++;
		}

	}

	sort(v.begin(), v.end());
	// for (auto it : v) {
	// 	cout << it.first << " " << it.second << '\n';
	// } cout << '\n';

	map<int, int> mp;
	for (auto it : st) {
		// cout << it.first << " " << it.second << '\n';
		mp[it.first - it.second] += mp2[ {it.first, it.second}];
	}

	int ans = 0;
	for (auto it : mp) {
		// cout << it.first << " " << it.second << "\n";
		int temp = (it.second * (it.second - 1)) / 2;
		temp *= 2;
		ans = max(ans, temp);
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