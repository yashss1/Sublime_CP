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

bool cmp(pair<int, int>&p1, pair<int, int>&p2) {
	if (p1.first != p2.first) return p1.first < p2.first;
	else {
		return p1.second > p2.second;
	}
}

void yash()
{
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;
	vector<pair<int, int>> temp;
	for (int i = 1; i < n; i++) {
		int a = v[i - 1], b = v[i];
		if (a > b) swap(a, b);

		temp.push_back({a, b});
		ans += abs(v[i - 1] - v[i]);
	}
	sort(temp.begin(), temp.end(), cmp);
	// for (auto it : temp) {
	// 	cout << it.first << " " << it.second << '\n';
	// }

	if (temp.size() == 0) {
		temp.push_back({v[0], v[0]});
	}

	vector<pair<int, int>> pairs;
	int l = temp[0].first, r = temp[0].second;
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i].first <= r) {
			r = max(r, temp[i].second);
		}
		else {
			pairs.push_back({l, r});
			l = temp[i].first, r = temp[i].second;
		}
	}
	pairs.push_back({l, r});

	sort(pairs.begin(), pairs.end());

	// for (auto it : pairs) {
	// 	cout << it.first << " " << it.second << '\n';
	// }

	pair<int, int> oneAndOnlyIg = pairs[0];
	pair<int, int> pehle, later;

	if (oneAndOnlyIg.first > 1) {
		pehle.first = 1;
		pehle.second = min(x, oneAndOnlyIg.first - 1);
	}

	if (oneAndOnlyIg.first <= x) {
		ans += (oneAndOnlyIg.first - 1);
	}
	// else {
	// 	ans += (x - 1);
	// 	ans += (oneAndOnlyIg.first - x);
	// }


	if (oneAndOnlyIg.second <= x) {
		ans += max(0ll, x - oneAndOnlyIg.second - 1); // taken lastss
		later.second = x;
		later.first = min(oneAndOnlyIg.second + 1, later.second);
	}

	cout << pehle.first << " " << pehle.second << '\n';
	cout << later.first << " " << later.second << '\n';

	if (v[0] == oneAndOnlyIg.first) {
		ans += (x - 1);
		ans += (oneAndOnlyIg.first - x);
	}
	else if (pehle.first != 0 && pehle.second != 0) {
		ans += max(0ll, oneAndOnlyIg.first - pehle.first);
	}

	if (later.first != 0 && later.second != 0 && oneAndOnlyIg.second != later.second) {
		ans += max(0ll, later.first - v[n - 1]);
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