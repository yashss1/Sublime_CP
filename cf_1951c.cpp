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


int n, m, k;
vector<pair<int, int>> v;
int flag = 0;

vector<vector<int>> dp;

int go(int idx, int taken) {
	if (idx == n) {
		return 0;
	}

	int &ans = dp[taken][idx];
	if (ans != -1) {
		return ans;
	}

	int c1 = 3e18, c2 = 3e18;
	if (taken == 0) {
		int byHowmuch = idx * m;
		int curr = ((v[idx].second + byHowmuch) * m);
		c2 = curr + go(idx + 1, 0);

		if (flag != 0) {
			curr = ((v[idx].second + byHowmuch) * (k % m));
			c1 = curr + go(idx + 1, 1);
		}
	}
	else {
		int byHowmuch = ((idx - 1) * m) + (k % m);
		int curr = ((v[idx].second + byHowmuch) * m);
		c2 = curr + go(idx + 1, taken);
	}

	return ans = min({c1, c2});
}

void yash()
{
	cin >> n >> m >> k;
	v.assign(n, {0, 0});
	dp.assign(2, vector<int>(n + 1, -1));

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		sum += v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	n = (k / m) + (k % m == 0 ? 0 : 1);
	flag = 1;
	if (k % m == 0) {
		flag = 0;
	}
	vector<pair<int, int>> temp;
	for (int i = 0; i < n; i++) {
		temp.push_back({v[i].second, v[i].first});
	}
	sort(temp.begin(), temp.end());
	v = temp;

	// for (auto it : v) {
	// 	cout << it.first << " " << it.second << '\n';
	// }
	// cout << flag << '\n';

	int ans = go(0, 0);
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