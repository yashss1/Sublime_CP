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

int n;
vector<int> v[N];
int dp[3][N];

int go(int idx, int prev) {
	if(idx == n) {
		return 0;
	}

	int &ans = dp[prev][idx];
	if(ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0, c3 = 0;
	if(prev != 0 || idx == 0) {
		c1 = v[idx][0] + go(idx + 1, 0);
	}
	if(prev != 1 || idx == 0) {
		c2 = v[idx][1] + go(idx + 1, 1);
	}
	if(prev != 2 || idx == 0) {
		c3 = v[idx][2] + go(idx + 1, 2);
	}

	return ans = max({c1, c2, c3});
}

void yash()
{
  cin >> n; 
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i++) {
  	vector<int> temp(3);
  	for(int j = 0; j < 3; j++) {
  		cin >> temp[j];
  	}
  	v[i] = temp;
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