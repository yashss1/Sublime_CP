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
const int N = 1e2 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

string s;
int n;
int o, z;
int dp[N][N];

int go(int idx, int ones, int zeros) {
	if (idx == n) {
		return 0;
	}

	int &ans = dp[idx][ones];
	if (ans != -1) {
		return ans;
	}

	int c1 = INT_MAX, c2 = INT_MAX;
	if (ones > 0) {
		c1 = (zeros) + go(idx + 1, ones - 1, zeros);
	}
	if (zeros > 0) {
		c2 = -(ones) + go(idx + 1, ones, zeros - 1);
	}
	return ans = min(c1, c2);
}

int go2(int idx, int ones, int zeros, int rem, vector<vector<vector<int> > > &dp2) {
	if (idx == n) {
		if (rem == 0) {
			return 0;
		}
		return INT_MAX;
	}
	int &ans = dp2[idx][ones][rem];
	if (ans != -1) {
		return ans;
	}
	int c1 = INT_MAX, c2 = INT_MAX;
	if (ones > 0 && rem - zeros >= 0) {
		c1 = go2(idx + 1, ones - 1, zeros, rem - zeros, dp2);
	}
	if (zeros > 0) {
		c2 = go2(idx + 1, ones, zeros - 1, rem, dp2);
	}
	return ans = min({c1, c2});
}

string yashh;
void trace(int idx, int ones, int zeros, int rem, vector<vector<vector<int> > > &dp2) {
	if (idx == n) {
		if (rem == 0) {
			return;
		}
		return;
	}

	int ans = dp2[idx][ones][rem];
	int c1 = INT_MAX, c2 = INT_MAX;
	if (ones > 0 && rem - zeros >= 0) {
		c1 = go2(idx + 1, ones - 1, zeros, rem - zeros, dp2);
		if (c1 == ans) {
			yashh += "1";
			trace(idx + 1, ones - 1, zeros, rem - zeros, dp2);
			return;
		}
	}
	if (zeros > 0) {
		c2 = go2(idx + 1, ones, zeros - 1, rem, dp2);
		if (c2 == ans) {
			yashh += "0";
			trace(idx + 1, ones, zeros - 1, rem, dp2);
			return;
		}
	}
	// return min({c1, c2});
}

int solve(string a, string b) {
	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			res++;
		}
	}
	return res / 2;
}

void yash()
{
	cin >> s;
	n = s.size();
	o = 0, z = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			z++;
		}
		else {
			o++;
		}
	}

	memset(dp, -1, sizeof(dp));
	int ans1 = go(0, o, z);
	ans1 /= 2; ans1 *= -1;

	vector<vector<vector<int> > > dp2(
	    n + 2, vector<vector<int> >(n + 2, vector<int>(ans1 + 1)));
	int ans2 = go2(0, o, z, ans1, dp2);
	yashh = "";
	trace(0, o, z, ans1, dp2);

	string yash2 = yashh;
	for (int i = 0; i < yash2.size(); i++) {
		if (yash2[i] == '1') {
			yash2[i] = '0';
		}
		else {
			yash2[i] = '1';
		}
	}

	// cout << yashh << "\n" << yash2 << "\n";
	int aa = solve(s, yashh);
	int bb = solve(s, yash2);
	cout << min(aa, bb) << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}