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
int N = 1e2 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*

*/

int n, m;
bool check(int x, int y, vector<vector<char>> &v)
{
  if (x < 0 || y < 0 || x >= n || y >= m)
    return false;
  if (v[x][y] == 'X') return false;
  return true;
}


int dp[105][105];

int go(int x, int y, int wantx, int wanty, int xDir, int yDir, vector<vector<char>> &v) {
  if (x == wantx && y == wanty) {
    return 0;
  }

  int &ans = dp[x][y];
  if (ans != -1) {
    return ans;
  }

  int c1 = INT_MIN, c2 = INT_MIN;
  if (check(x + xDir, y, v)) {
    c1 = (v[x + xDir][y] == '$') + go(x + xDir, y, wantx, wanty, xDir, yDir, v);
  }
  if (check(x, y + yDir, v)) {
    c2 = (v[x][y + yDir] == '$') + go(x, y + yDir, wantx, wanty, xDir, yDir, v);
  }

  return ans = max({c1, c2});
}

void trace(int x, int y, int wantx, int wanty, int xDir, int yDir, vector<vector<char>> &v) {
  if (x == wantx && y == wanty) {
    return;
  }

  int ans = dp[x][y];


  int c1 = INT_MIN, c2 = INT_MIN;
  if (check(x + xDir, y, v)) {
    c1 = (v[x + xDir][y] == '$') + go(x + xDir, y, wantx, wanty, xDir, yDir, v);
    if (c1 == ans) {
      v[x + xDir][y] = '*';
      trace(x + xDir, y, wantx, wanty, xDir, yDir, v);
      return;
    }
  }
  if (check(x, y + yDir, v)) {
    c2 = (v[x][y + yDir] == '$') + go(x, y + yDir, wantx, wanty, xDir, yDir, v);
    if (c2 == ans) {
      v[x][y + yDir] = '*';
      trace(x, y + yDir, wantx, wanty, xDir, yDir, v);
      return;
    }
  }

  assert(false);
}

vector<vector<char>> a, b;
int yash()
{
  memset(dp, -1, sizeof(dp));
  int ans1 = go(0, n - 1, n - 1, 0, 1, -1, b);
  trace(0, n - 1, n - 1, 0, 1, -1, b);

  memset(dp, -1, sizeof(dp));
  int ans2 = go(n - 1, 0, 0, n - 1, -1, 1, b);

  memset(dp, -1, sizeof(dp));
  int ans3 = go(n - 1, n - 1, 0, 0, -1, -1, a);
  trace(n - 1, n - 1, 0, 0, -1, -1, a);

  memset(dp, -1, sizeof(dp));
  int ans4 = go(0, 0, n - 1, n - 1, 1, 1, a);

  int ans = ans1 + ans2 + ans3 + ans4;
  return ans;
}

int GetMaxMangoes(vector<string> v) {
  n = v.size();
  m = v[0].size();

  a.assign(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = v[i][j];
    }
  }

  b = a;
  for (int i = 0; i < n; i++) {
    reverse(b[i].begin(), b[i].end());
  }
  int ans = yash();
  return ans;
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // test
  // yash();
  return 0;
}