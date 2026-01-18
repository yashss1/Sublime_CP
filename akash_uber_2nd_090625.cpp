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

void yash()
{
  string s;
  cin >> s;
  int cr; cin >> cr;

  map<char, int> mp;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }

  int ans = 0;
  while (1) {
    if (mp['P'] >= cr) {
      mp['P'] -= cr;
      mp['A']++;
    } else if (mp['A'] >= 1) {
      mp['P']++;
      mp['A']--;
    } else {
      break;
    }
    ans++;
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