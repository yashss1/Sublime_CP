//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<"";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, k;
int d1, d2;
string num;

vector<vector<vector<int>>> dp;
string finalAnswer;

int go(int idx, int lower, int mask) {
	if (idx == num.size()) {
		if (k == 1 && mask == 1) {
			return 1;
		}
		if (k == 2 && (mask == 3 || mask == 1)) {
			return 1;
		}
		return 0;
	}

	int &ans = dp[lower][mask][idx];
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	for (int i = 0; i < 10; i++) {
		if (d1 != i && d2 != i) continue;
		if (lower && ((num[idx] - '0') > i)) continue;
		if (d1 == i) mask |= 1;
		if (k != 1 && d2 == i) mask |= 2;
		ans |= go(idx + 1, lower && ((num[idx] - '0') == i), mask);
	}

	return ans;
}

void trace(int idx, int lower, int mask) {
	if (idx == num.size()) {
		return;
	}

	int ans = dp[lower][mask][idx], chk = 0;
	for (int i = 0; i < 10; i++) {
		if (d1 != i && d2 != i) continue;
		if (lower && ((num[idx] - '0') > i)) continue;
		if (d1 == i) mask |= 1;
		if (k != 1 && d2 == i) mask |= 2;
		chk |= go(idx + 1, lower && ((num[idx] - '0') == i), mask);
		if (ans == chk) {
			finalAnswer.push_back('0' + i);
			trace(idx + 1, lower && ((num[idx] - '0') == i), mask);
			return;
		}
	}

	assert(false);
}

int to_integer(string s) {
	int num = 0;
	for (char c : s) {
		if (c >= '0' && c <= '9') {
			num = num * 10 + (c - '0');
		}
	}
	return num;
}

void yash()
{
	cin >> n >> k;

	num = to_string(n);

	int finalfinalAnswer = INT_MAX;

	// only one digit
	for (int i = 0; i < 10; i++) {
		d1 = i; d2 = i;
		int temp = 0;
		finalAnswer.clear();
		dp.assign(2, vector<vector<int>>(5, vector<int>(11, -1)));
		for (int j = num[0] - '0'; j < 10; j++) {
			if (j != d1 && j != d2) continue;
			temp |= go(1, (j == num[0] - '0'), 1);
			if (temp == 1) {
				finalAnswer.push_back(j + '0');
				trace(1, (j == num[0] - '0'), 1);
				int res = to_integer(finalAnswer);
				finalfinalAnswer = min(finalfinalAnswer, res);
				break;
			}
		}
	}

	// only two digits
	if (k == 2) {
		vector<int> idk = {num[0] - '0'};
		if (num[0] != '9') idk.push_back(num[0] - '0' + 1);
		for (auto i : idk) {
			for (int k = 0; k < 10; k++) {
				if (i == k) continue;
				d1 = i, d2 = k;
				int temp = 0;
				finalAnswer.clear();
				dp.assign(2, vector<vector<int>>(5, vector<int>(11, -1)));
				for (int j = num[0] - '0'; j < 10; j++) {
					if (j != d1 && j != d2) continue;
					int mask = 0;
					if (d1 == j) mask |= 1;
					if (d2 == j)mask |= 2;

					temp |= go(1, (j == num[0] - '0'), mask);
					if (temp == 1) {
						finalAnswer.push_back('0' + j);
						trace(1, (j == num[0] - '0'), mask);
						int res = to_integer(finalAnswer);
						finalfinalAnswer = min(finalfinalAnswer, res);
						break;
					}
				}
			}
		}
	}
	cout << finalfinalAnswer << "\n";
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