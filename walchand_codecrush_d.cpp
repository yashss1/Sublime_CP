#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<int> v(N);
int dp[N];

int go(int idx) {
	if(idx > n) {
		return 0;
	}
	if(idx == n) {
		return 1;
	}

	int &ans = dp[idx];
	if(ans != -1) {
		return ans;
	} 
	ans = 0;

	int c1 = 0;
	for(int i = 1; i <= v[idx]; i++) {
		c1 |= go(idx + i);
	}
	return ans = c1;
}

void solve()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	dp[i] = -1;
  }
  dp[n] = -1;

  if(go(0)) {
  	cout << "Yes\n";
  	return;
  }
  cout << "No\n";
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  test
  solve();
  return 0;
}