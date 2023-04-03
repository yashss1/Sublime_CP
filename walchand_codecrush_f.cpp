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
  int R, C;
  cin >> R >> C;

  int N;
  cin >> N;
  vector<vector<pair<int, int>>> A(R + 1), B(C  + 1);
  for (int i = 0; i < N; ++i) {
    int r, c, a;
    cin >> r >> c >> a;
    --r;
    --c;
    A[r].emplace_back(c, a);
    B[c].emplace_back(r, a);
  }

  vector < bool > usedR(R, false), usedC(C, false);
  vector < int > valueR(R), valueC(C);

  queue < pair < bool, int >> Q;
  for (int i = 0; i < R; ++i)
    if (!usedR[i]) {
      if (A[i].empty())
        continue;
      Q.push({true, i});
      valueR[i] = 0;
      
      vector < int > componentR, componentC;
      usedR[i] = true;
      while (!Q.empty()) {
        bool isRow;
        int node;
        tie(isRow, node) = Q.front();
        Q.pop();
        if (isRow) {
          componentR.emplace_back(node);
          for (auto & c: A[node]) {
            if (usedC[c.first]) {
              if (valueC[c.first] + valueR[node] != c.second) {
                cout << "No\n";
                return;
              }
              continue;
            }
            usedC[c.first] = true;
            valueC[c.first] = c.second - valueR[node];
            Q.push({false, c.first});
          }
        } else {
          componentC.emplace_back(node);
          for (auto & r: B[node]) {
            if (usedR[r.first]) {
              if (valueR[r.first] + valueC[node] != r.second) {
                cout << "No\n";
                return;
              }
              continue;
            }
            usedR[r.first] = true;
            valueR[r.first] = r.second - valueC[node];
            Q.push({true, r.first});
          }
        }
      }

      int maxt = numeric_limits < int > ::max();
      int mint = 0;
      for (auto & v: componentR)
        mint = max(mint, -valueR[v]);
      for (auto & v: componentC)
        maxt = min(maxt, valueC[v]);
      if (maxt < mint) {
        cout << "No\n";
        return;
      }
    }
  cout << "Yes\n";
}

signed main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // test
  solve();
  return 0;
}