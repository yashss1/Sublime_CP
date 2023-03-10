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

// Lisa and queries
void yash()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<int> hsh(n + 1, 0);
  for(int i = 1; i < n; i++) {
      hsh[i + 1] = hsh[i];
      if(s[i] == s[i - 1]) {
          hsh[i + 1]++;
      }
  }
  int q;
  cin >> q;
  while(q--) {
      int l, r;
      cin >> l >> r;
      int ans = hsh[r] - hsh[l];
      cout << ans << '\n';
  }

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




