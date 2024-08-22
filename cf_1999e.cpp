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

vector<int> dp(2e5 + 2);

void yash()
{
	int l, r;
	cin >> l >> r; 

	int ans = 0;
	int temp = l;
		while(temp != 0) {
			ans++;
			temp /= 3;
		}
	
	ans *= 2;

	l++;

	ans += (dp[r] - dp[l - 1]);
	cout << ans << '\n';
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  dp[0] = 0;
  for(int i = 1; i <= 2e5; i++) {
  	int L = 0;
  	int temp = i;
		while(temp != 0) {
			temp /= 3;
			L++;
		}
		dp[i] = dp[i - 1] + L;
  }
  // for(int i = 0; i < 100; i++) {
  // 	cout << dp[i] << " ";
  // }cout << '\n';

  test
  yash();
  return 0;
}