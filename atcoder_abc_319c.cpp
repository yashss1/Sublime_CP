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

int v[3][3];

int check(int x, int y, int mask) {
  if (x >= 3 || y >= 3 || x < 0 || y < 0) {
    return 0;
  }
  int bit = (x * 3) + (y);


  if (!((1 << bit) & mask)) {
    return 0;
  }

  return 1;
}

int go(int mask, int count) {
  if (count == 9) {
    return 1;
  }

  int ans = 0;
  for (int i = 0; i < 9; i++) {
    int x = (i / 3), y = (i % 3);

    if (!((1 << i) & mask)) {
      map<int, int> a, b, c;
      if (check(x + 1, y, mask)) {
        a[v[x + 1][y]]++;
      }
      if (check(x + 2, y, mask)) {
        a[v[x + 2][y]]++;
      }
      if (check(x - 1, y, mask)) {
        a[v[x - 1][y]]++;
      }
      if (check(x - 2, y, mask)) {
        a[v[x - 2][y]]++;
      }

      if (check(x, y + 1, mask)) {
        b[v[x][y + 1]]++;
      }
      if (check(x, y + 2, mask)) {
        b[v[x][y + 2]]++;
      }
      if (check(x, y - 1, mask)) {
        b[v[x][y - 1]]++;
      }
      if (check(x, y - 2, mask)) {
        b[v[x][y - 2]]++;
      }

      if (check(x + 1, y + 1, mask)) {
        c[v[x + 1][y + 1]]++;
      }
      if (check(x + 2, y + 2, mask)) {
        c[v[x + 2][y + 2]]++;
      }
      if (check(x - 1, y - 1, mask)) {
        c[v[x - 1][y - 1]]++;
      }
      if (check(x - 2, y - 2, mask)) {
        c[v[x - 2][y - 2]]++;
      }


      int flag = 0;
      for (auto it : a) {
        if (it.second > 2) {
          assert(false);
        }

        if (it.second == 2) {
          int num = it.first;
          if (v[x][y] != num) {
            flag = 1;
          }
        }
      }
      for (auto it : b) {
        if (it.second > 2) {
          assert(false);
        }

        if (it.second == 2) {
          int num = it.first;
          if (v[x][y] != num) {
            flag = 1;
          }
        }
      }
      for (auto it : c) {
        if (it.second > 2) {
          assert(false);
        }

        if (it.second == 2) {
          int num = it.first;
          if (v[x][y] != num) {
            flag = 1;
          }
        }
      }

      if (flag == 0) {
        ans += go(mask ^ (1 << i), count + 1);
      }

    }
  }
  return ans;
}

void yash()
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v[i][j];
    }
  }


  int mask = 0;

  int ans = go(mask, 0);
  cout << ans << '\n';

  double res = (ans / (float)362880);
  cout << fixed << setprecision(10) << res << "\n";
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
