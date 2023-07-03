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
const int N = 3e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

string s, l, r;
int m, n;
map<int, vector<int>> mp;
int dp[11][N];

int go(int idx, int id) {
	if (idx == m) {
		return 0;
	}

	int &ans = dp[idx][id];
	if (ans != -1) {
		return ans;
	}


	ans = 0;
	for (int i = l[idx] - '0'; i <= r[idx] - '0'; i++) {
		int l = 0, r = mp[i].size() - 1, curr = -1;

		if (mp[i].size() > 0) {
			if (mp[i][mp[i].size() - 1] < id) {
				return 1;
			}
		}
		else {
			return 1;
		}

		while (l <= r) {
			int mid = (l + r) / 2;
			if (mp[i][mid] > id) {
				curr = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		if (curr == -1) {
			return 1;
		}

		ans |= go(idx + 1, mp[i][curr]);
	}

	return ans;
}

void yash()
{
	cin >> s >> m >> l >> r;
	n = s.size();
	mp.clear();
	s = "#" + s;
	for (int i = 1; i < s.size(); i++) {
		mp[s[i] - '0'].push_back(i);
	}
	for (int i = 0; i < n + 5; i++) {
		for (int j = 0; j < m + 1; j++) {
			dp[j][i] = -1;
		}
	}

	int ans = go(0, 0);


	if (ans == 1) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";

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