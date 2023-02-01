//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 998244353;
const int N = 1e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
 
int n, K;

/*
prev

0 -> 0 1 0 1
0 	 0 0 1 1

1 -> 
0

0 ->
1

1 -> 
1
*/

int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};

int mod_add(int a, int b) {
	a %= MOD; b %= MOD;
	return ((a + b) % MOD);
}

int dp[4][N][2*N];

int go(int idx, int k, int prev) {
	if(idx == n) {
		int differ = 0;
		if(dx[prev] == dy[prev]) differ++;
		else differ+=2;

		if(k - differ == 0) {
			return 1;
		}
		return 0;
	}

	if(k <= 0) {
		return 0;
	}

	int &ans = dp[prev][idx][k];
	if(ans != -1) {
		return ans;
	}

	ans = 0;

	for(int i = 0; i < 4; i++) {
		int change = 0;
		if(prev == i) {}
		else if(abs(prev - i) == 3)change += 1;
		else if(prev == 0 || prev == 3){}
		else {
			change += (dx[i] != dx[prev]) + (dy[i] != dy[prev]);
		}

		ans = mod_add(ans, go(idx + 1, k - change, i));
	}
	
	return ans;
}

void yash()
{
  memset(dp, -1, sizeof(dp));	
  cin >> n >> K;

  int ans = 0;
  for(int i = 0; i < 4; i++) {
  	ans = mod_add(ans, go(1, K, i));
  }

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