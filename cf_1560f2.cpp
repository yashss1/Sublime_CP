//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
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
string num;

int dp[2][10][(1 << 10)];

int go(int idx, int lower, int mask) {
	if (idx == num.size()) {
		if (__builtin_popcount(mask) <= k) {
			return 1;
		}
		return 0;
	}

	int &ans = dp[lower][idx][mask];
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	for (int i = (lower ? (num[idx] - '0') : 0); i < 10; i++) {
		if (lower && (i < (num[idx] - '0'))) continue;

		ans |= go(idx + 1, lower && ((num[idx] - '0') == i), mask | (1 << i));
		if (ans == 1) {
			break;
		}
	}

	return ans;
}

void trace(int idx, int lower, int mask) {
	if (idx == num.size()) {
		return;
	}

	int ans = dp[lower][idx][mask], chk = 0;
	for (int i = (lower ? (num[idx] - '0') : 0); i < 10; i++) {
		if (lower && ((num[idx] - '0') > i)) continue;
		chk |= go(idx + 1, lower && ((num[idx] - '0') == i), mask | (1 << i));
		if (ans == chk) {
			cout << i;
			trace(idx + 1, lower && ((num[idx] - '0') == i), mask | (1 << i));
			return;
		}
	}
	assert(false);
}

void yash()
{
	cin >> n >> k;

	num = to_string(n);
	int temp = 0;

	for (int i = num[0] - '0'; i < 10; i++) {
		temp |= go(1, (i == (num[0] - '0')), (1 << i));
		if (temp == 1) {
			cout << i;
			trace(1, (i == (num[0] - '0')), (1 << i));
			break;
		}
	}
	cout << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	test
	yash();
	return 0;
}