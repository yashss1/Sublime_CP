//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

string s;
int n;

// want = a0, b1
vector<vector<vector<vector<int>>>> dp;

int go(int idx, int a, int b, int flag) {
	if (idx == n) {
		return (!flag);
	}

	int &ans = dp[idx][a][b][flag];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	int c1 = 0, c2 = 0;
	if (s[idx] == 'a') {
		if (a && b) {
			if (flag) c2 = go(idx + 1, a, b, 1);
			else {
				c1 = go(idx + 1, (1 | a), b, 1);
				c2 = go(idx + 1, a, b, 0);
			}
		}
		else {
			c1 = go(idx + 1, (1 | a), b, flag);
			c2 = go(idx + 1, a, b, flag);
		}
	}
	else {
		if (a == 0) {
			c2 = go(idx + 1, a, b, flag);
		}
		else {
			if (a && b) {
				if (flag) {
					c1 = go(idx + 1, a, (1 | b), 0);
					c2 = go(idx + 1, a, b, flag);
				}
				else c2 = go(idx + 1, a, b, flag);
			}
			else {
				c1 = go(idx + 1, a, (1 | b), flag);
				c2 = go(idx + 1, a, b, flag);
			}
		}
	}

	return ans = (c1 + c2) % MOD;
}

void yash()
{
	cin >> s;
	n = s.size();

	dp.assign(n + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, (vector<int>(2, -1)))));
	int ans = (go(0, 0, 0, 0) - 1 + MOD) % MOD;
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
