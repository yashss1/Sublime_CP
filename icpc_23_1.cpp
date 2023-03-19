// YashS
#include <bits/stdc++.h>
using namespace std;
// #define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 2e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
string s, m;
int dp[N][N];
int go(int i, int j) {
	if(i == n) {
		return 1;
	}

	int &ans = dp[i][j];
	if(ans != -1) {
		return ans;
	}

	int p = j, q = (n - 1) - (i - j);
	int c1 = 0, c2 = 0;
	if(m[p] == s[i]) {
  		c1 = go(i + 1, j + 1);
  	}
  	if(m[q] == s[i]) {
  		c2 = go(i + 1, j);
  	}

  	return ans = (c1 | c2);
}

void yash()
{
  cin >> n;
  cin >> s >> m;
  reverse(all(s));
  for(int i = 0; i < n + 2; i++) {
  	for(int j = 0; j < n + 2; j++) {
  		dp[i][j] = -1;
  	}
  }

  // int p = 0, q = n - 1;
  // for(int i = 0; i < n; i++) {
  // 	if(m[p] == s[i]) {
  // 		p++;
  // 	}
  // 	else if(m[q] == s[i]) {
  // 		q--;
  // 	}
  // 	else {
  // 		cout << "NO\n";
  // 		return;
  // 	}
  // }



  int ans = go(0, 0);
  if(ans == 1) {
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
  int T;
  cin >> T;
  for(int i = 0; i < T; i++) {
  	cout << "Case " << i + 1 << ": ";
  	yash();
  }
  return 0;
}