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

int n;
vector<int> v(60);

vector<vector<int>> dp;

int go(int idx, int prev) {
	if (idx == n) {
		return 1;
	}

	int &ans = dp[idx][prev];
	if (ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0;

	// break
	string s = to_string(v[idx]);
	string temp = s;
	sort(all(s));
	if (s == temp) {
		if (s[0] - '0' >= prev) {
			c1 = go(idx + 1, s[s.size() - 1] - '0');
		}
	}


	// dont
	if (v[idx] >= prev) {
		c2 = go(idx + 1, v[idx]);
	}

	return ans = c1 || c2;
}

void yash()
{
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp.assign(n, vector<int>(100, -1));

	int ans = 0;
	ans = go(1, v[0]);
	string s = to_string(v[0]);
	string temp = s;
	sort(all(s));
	if (s == temp) {
		ans |= go(1, s[s.size() - 1] - '0');
	}

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