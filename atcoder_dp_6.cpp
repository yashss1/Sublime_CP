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
const int N = 3e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

string s, t;
int n, m;
int dp[N][N];

int go(int i, int j) {
	if(i > n || j > m) {
		return INT_MIN;
	}
	if(i == n && j == m) {
		return 0;
	}

	int &ans = dp[i][j];
	if(ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0, c3 = 0;
	if(s[i] == t[j] && i < n && j < m) {
		c1 = 1 + go(i + 1, j + 1);
	}
	else {
		c2 = go(i + 1, j);
		c3 = go(i, j + 1);
	}

	return ans = max({c1, c2, c3});
}

void trace(int i, int j) {
	if(i > n || j > m) {
		return;
	}
	if(i == n && j == m) {
		return;
	}

	int ans = dp[i][j];

	int c1 = 0, c2 = 0, c3 = 0;
	if(s[i] == t[j] && i < n && j < m) {
		c1 = 1 + go(i + 1, j + 1);
		if(c1 == ans) {
			cout << s[i];
			trace(i + 1, j + 1);
			return;
		}
	}
	else {
		c2 = go(i + 1, j);
		if(c2 == ans) {
			trace(i + 1, j);
			return;
		}
		c3 = go(i, j + 1);
		if(c3 == ans) {
			trace(i, j + 1);
			return;
		}
	}
	assert(false);
}

void yash()
{
  cin >> s >> t; 
  n = s.size();
  m = t.size();
  memset(dp, -1, sizeof(dp));

  int ans = go(0, 0);
  // cout << ans << '\n';
  trace(0, 0);
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