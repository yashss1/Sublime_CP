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
	vector<int> a(n), b(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n + 1; i++) {
		cin >> b[i];
	}

	// pVec(a);
	// pVec(b);

	set<pair<int, int>> ranges;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			ranges.insert({a[i], b[i]});
			ans += (b[i] - a[i]);
		}
		else {
			ranges.insert({b[i], a[i]});
			ans += (a[i] - b[i]);
		}
	}

	vector<pair<int, int>> res(ranges.begin(), ranges.end());

	vector<pair<int, int>> ress;
	sort(all(res));


	int flag = 0;
	for (auto it : res) {
		if (b[n] >= it.first && b[n] <= it.second) {
			flag = 1;
		}
	}

	int l = res[0].first, r = res[0].second;
	for (int i = 1; i < res.size(); i++) {
		if (res[i].first > r) {
			ress.push_back({l, r});
			l = res[i].first;
			r = max(r, res[i].second);
		}
		else {
			r = max(r, res[i].second);
		}
	}
	ress.push_back({l, r});

	if (flag == 1) {
		ans++;
	}
	else {
		int temp = b[n];
		int mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			mn = min(mn, abs(a[i] - temp));
			mn = min(mn, abs(b[i] - temp));
		}
		ans += (mn + 1);
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