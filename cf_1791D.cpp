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

void yash()
{
  int n;
  cin >> n; 
  string s;
  cin >> s;

  vector<vector<int>> v;
  v.resize(n + 2, vector<int>(26, 0));

  for(int i = 1; i <= n; i++) {
  	// cout << v[i - 1][0] << '\n';
  	for(int j = 0; j < 26; j++) {
  		v[i][j] = ((s[i - 1] - 'a' == (j)) + v[i - 1][j]);
  	}
  }


  // for(int i = 0; i <= n; i++) {
  	// cout << v[i][0] << " ";
  // }
  // cout << '\n';

  int ans = 0;
  for(int i = 2; i <= n; i++) {
  	set<int> st;
  	int a = 0, b = 0;
  	for(int j = 0; j < 26; j++) {
  		int t = v[i - 1][j];
  		int t1 = v[n][j] - v[i - 1][j];
  		if(t > 0) {
  			a++;
  		}
  		if(t1 > 0) {
  			b++;
  		}
  	}
  		
  	ans = max(ans, a + b);
  }

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