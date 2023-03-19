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

int n, w;
vector<pair<int, int>> v(N);
int dp[101][N];

int go(int idx, int weigh) {
	if(weigh > w) {
		return INT_MIN;
	}
	if(idx == n) {
		return 0;
	}

	int &ans = dp[idx][weigh];
	if(ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0, c3 = 0;
	c1 = v[idx].second + go(idx + 1, weigh + v[idx].first);
	c2 = go(idx + 1, weigh);

	return ans = max({c1, c2});
}

void yash()
{
  cin >> n >> w; 
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i++) {
  	cin >> v[i].first >> v[i].second;
  }

  int ans = go(0, 0);
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