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

string s;
int n, k;
int K = 10;

vector<vector<vector<vector<int>>>> dp;

int go(int idx, int edge, int mask, int taken) {
	if (idx == n) {
		for (int i = 0; i < 10; i++) {
			if (taken & (1 << i)) {
				return 0;
			}
		}
		return 1;
	}

	int &ans = dp[edge][idx][mask][taken];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = s[idx] - '0'; i < 10; i++) {
		if (edge == 1 && (i < s[idx] - '0')) {
			continue;
		}

		if (mask & (1 << i)) {
			if ((taken & (1 << i))) {
				taken ^= (1 << i);
			}

			ans |= go(idx + 1, edge && (i == (s[idx] - '0')), mask, taken);
		}
	}
	for (int i = 0; i < s[idx] - '0'; i++) {
		if (edge == 1 && (i < s[idx] - '0')) {
			continue;
		}

		if (mask & (1 << i)) {
			if ((taken & (1 << i))) {
				taken ^= (1 << i);
			}

			ans |= go(idx + 1, edge && (i == (s[idx] - '0')), mask, taken);
		}
	}
	return ans;
}

string num;
void trace(int idx, int edge, int mask, int taken) {
	if (idx == n) {
		for (int i = 0; i < 10; i++) {
			if (taken & (1 << i)) {
				return;
			}
		}
		return;
	}

	int ans = dp[edge][idx][mask][taken];

	int curr = 0;
	for (int i = s[idx] - '0'; i < 10; i++) {
		if (edge == 1 && (i < s[idx] - '0')) {
			continue;
		}

		if (mask & (1 << i)) {
			if ((taken & (1 << i))) {
				taken ^= (1 << i);
			}

			curr |= go(idx + 1, edge && (i == (s[idx] - '0')), mask, taken);
			if (ans == curr) {
				// cout << i;
				num.push_back((char)(i + '0'));
				trace(idx + 1, edge && (i == (s[idx] - '0')), mask, taken);
				return;
			}
		}
	}
	for (int i = 0; i < s[idx] - '0'; i++) {
		if (edge == 1 && (i < s[idx] - '0')) {
			continue;
		}

		if (mask & (1 << i)) {
			if ((taken & (1 << i))) {
				taken ^= (1 << i);
			}

			curr |= go(idx + 1, edge && (i == (s[idx] - '0')), mask, taken);
			if (ans == curr) {
				// cout << i;
				num.push_back((char)(i + '0'));
				trace(idx + 1, edge && (i == (s[idx] - '0')), mask, taken);
				return;
			}
		}
	}
	assert(false);
}

void yash()
{
	cin >> s >> k;
	n = s.size();

	dp.assign(2, vector<vector<vector<int>>>(10, vector<vector<int>>(1024, vector<int>(1024, -1))));

	int ans = 0;
	for (int i = 0; i < pow(2, K); i++) {
		int sett = 0;
		for (int j = 0; j < K; j++) {
			if (i & (1 << j)) {
				sett++;
			}
		}
		if (sett != k) continue;
		cout << i << "\n";

		// for (int j = s[0] - '0'; j < 10; j++) {
		// 	ans |= go(1, j == (s[0] - '0'), i, i);
		// 	// if (ans == 1) {
		// 	// 	cout << i << " " << j << '\n';
		// 	// }
		// }
	}

	cout << ans << '\n';
	return;

	vector<int> res;
	int curr = 0;
	for (int i = 0; i < pow(2, K); i++) {
		int sett = 0;
		for (int j = 0; j < K; j++) {
			if (i & (1 << j)) {
				sett++;
			}
		}
		if (sett != k) continue;
		// cout << i << "\n";

		for (int j = s[0] - '0'; j < 10; j++) {
			curr |= go(1, j == (s[0] - '0'), i, i);
			if (ans == curr) {
				// cout << j;
				num.clear();
				num.push_back((char)(j + '0'));
				trace(1, j == (s[0] - '0'), i, i);
				// cout << '\n';
				// cout << num << '\n';
				// return;
				res.push_back(stoi(num));
			}
		}
	}

	pVec(res);
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