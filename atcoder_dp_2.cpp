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
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, k;
vector<int> v(N);
int dp[N];
int go(int idx) {
	if(idx == n - 1) {
		return 0;
	}

	int &ans = dp[idx];
	if(ans != -1) {
		return ans;
	}
	int c1 = INT_MAX;
	for(int i = idx + 1; i <= min(n - 1, idx + k); i++) {
		c1 = min(c1, abs(v[i] - v[idx]) + go(i));
	}
	return ans = c1;
}

void yash()
{
  cin >> n >> k; 
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	dp[i] = -1;
  }

  int ans = go(0);
  cout << ans << '\n';
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