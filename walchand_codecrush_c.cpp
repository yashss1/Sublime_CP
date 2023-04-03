#include <bits/stdc++.h>

using namespace std;
#define test int T;cin >> T;while (T--)
#define int long long
const int N = 1e5 + 7;

void init_code() {
  #ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
  #endif // ONLINE_JUDGE
}

void solve() {
  int n;
  cin >> n;
  map < pair < int, int > , unordered_set < double >> mp;
  int mx = 1;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int g = __gcd(a, b);
    double d = c * 1.0;
    mp[{
      a / g,
      b / g
    }].insert(d / g);

  }
  for (auto d: mp) {
    mx = max(mx, (int) d.second.size());
  }
  cout << mx << "\n";
}

signed main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  test
  solve();
  return 0;
}