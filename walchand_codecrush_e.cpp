#include <bits/stdc++.h>

using namespace std;
#define test int T; cin >> T; while (T--)
#define int long long

void init_code() {
  #ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
  #endif // ONLINE_JUDGE
}

void solve() {
  int n;
  cin >> n;
  vector < pair < int, int >> a;
  vector < pair < int, int >> b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        a.push_back({
          i,
          j
        });
      } else {
        b.push_back({
          i,
          j
        });
      }
    }
  }
  if (b.empty()) {
    cout << "-1\n";
    return;
  }
  int max_dist = 0;
  for (auto it: b) {
    int min_dist = INT_MAX;
    for (auto tw: a) {
      int dist = abs(tw.first - it.first) + abs(tw.second - it.second);
      min_dist = min(min_dist, dist);
    }
    max_dist = max(max_dist, min_dist);
  }
  cout << max_dist << "\n";
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