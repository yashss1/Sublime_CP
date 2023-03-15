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
const int N = 5e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<int> v(N);
string a, b;
vector<vector<vector<int>>> dp;

int go(int idx, int naruto, int jiraya) {
	if(idx == n) {
		if(naruto == 0 || jiraya == 0) {
			return INT_MAX;
		}
		return abs(naruto - jiraya);
	}


	int &ans = dp[idx][naruto][jiraya];
	if(ans != -1) {
		return ans;
	}

	int c1 = go(idx + 1, naruto + ((a[idx] == '1') ? (v[idx]) : (0)), jiraya);
	int c2 = go(idx + 1, naruto, jiraya + ((b[idx] == '1') ? (v[idx]) : (0)));

	return ans = min({c1, c2});
}

void yash()
{
  cin >> n; 
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }
  cin >> a >> b;
  int sum1 = 0;
  int sum2 = 0;

  for(int i = 0; i < n; i++) {
  	if(a[i] == '1') {
  		sum1 += v[i];
  	}
  	if(b[i] == '1') {
  		sum2 += v[i];
  	}
  }
  // cout << a << " " << b << "\n";

  dp.assign(n + 2, vector<vector<int>>(sum1 + 1, vector<int>(sum2 + 1, -1)));

  int ans = go(0, 0, 0);
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