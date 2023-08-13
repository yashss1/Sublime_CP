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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, k;
vector<int> v(N);
map<int, vector<int>> mp;

int dp[N];

int go(int idx) {
	if (idx > n) {
		return 0;
	}
	if (idx == n) {
		return 1;
	}

	int &ans = dp[idx];
	if (ans != -1) {
		return ans;
	}

	int l = 0, r = mp[v[idx]].size() - 1;
	int curr = mp[v[idx]].size();
	while (l <= r) {
		int mid = (l + r) / 2;
		if (mp[v[idx]][mid] >= idx) {
			curr = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	// cout << curr + k - 1 << " " << mp[v[idx]].size() << "\n";
	// return 0;


	if (v[n - 1] == v[idx]) {
		// cout << idx << " " << mp[v[idx]].size() << " | " << curr + k - 1 << "\n";
		if (mp[v[idx]].size() > curr + k - 1) {
			// cout << "ASDS\n";
			return 1;
		}
	}
	// cout << idx << " " << curr << '\n';

	int c1 = 0;
	if (curr + k - 1 < mp[v[idx]].size()) {
		c1 = go(mp[v[idx]][curr + k - 1] + 1);
	}
	int c2 = 0;
	if (idx != n - 1 && idx != 0) {
		c2 = go(idx + 1);
	}

	// return 0;
	return ans = c1 || c2;
}

void yash()
{
	cin >> n >> k;
	mp.clear();
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]].push_back(i);
	}

	for (int i = 0; i <= n + 1; i++) {
		dp[i] = -1;
	}

	// for (auto it : mp) {
	// 	cout << it.first << " -> ";
	// 	pVec(it.second);
	// }
	// cout << mp[0][]

	if (mp[v[0]].size() < k) {
		cout << "NO\n";
		return;
	}

	// cout << mp[v[0]][k - 1] + 1 << "\n";

	int ans = go(0);
	if (ans == 1) {
		cout << "YES\n"; return;
	}
	else {
		cout << "NO\n";
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