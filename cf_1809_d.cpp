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
const int N = 3e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
string s;
int dp[2][2][N];

int go(int idx, int swapped, int thisDo) {
	if(idx == n) {
		return 0;
	}

	int &ans = dp[thisDo][swapped][idx];
	if(ans != -1) {
		return ans;
	}

	int curr = s[idx] - '0';
	if(swapped) {
		curr ^= 1;	
	}

	int c1 = 1e18, c2 = 1e18;
	if(idx + 1 < n && s[idx + 1] - '0' != curr && thisDo == 0 && curr == 1) {
		if(swapped == 0) {
			c1 = (1e12) + go(idx + 1, 1, 0);
		}
	}
	else {
		if(curr == 1) {
			c1 = go(idx + 1, 0, 1);
		}
		else if(thisDo == 1) {

		} 
		else {
			c1 = go(idx + 1, 0, 0);
		}
	}

	c2 = (1e12 + 1ll) + go(idx + 1, 0, thisDo);

	return ans = min({c1, c2});
}

void yash()
{
  cin >> s;
  n = s.size();
  memset(dp, -1, sizeof(dp));
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