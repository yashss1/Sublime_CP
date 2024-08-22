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
int N = 2e5 + 7;
void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m;
vector<int> vis;
map<pair<int, int>, pair<int, int>> parent;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<char>> v;
vector<vector<int>> dist[2];
int iii, jjj;


bool check(int x, int y)
{
  if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
    return false;
  if (vis[(x * 1000) + y] == 1)
    return false; // If visited returns false
  if (v[x][y] == '#') return false;
  return true;
}

int gotIt = 0;
void bfs(int x, int y) {
  queue<pair<pair<int, int>, int>> q;

  q.push({{x, y}, 0});
  dist[1][x][y] = 0;
  vis[ (x * 1000) + y] = 1;

  while (!q.empty()) {
    pair<int, int> temp = q.front().first;
    int distance = q.front().second;
    q.pop();
    if (temp.first == n - 1 || temp.second == m - 1 || temp.first == 0 || temp.second == 0) {
      gotIt = 1;
      iii = temp.first, jjj = temp.second;
    }


    for (int i = 0; i < 4; i++)
    {
      int X = temp.first + dx[i];
      int Y = temp.second + dy[i];
      if (!check(X, Y))
        continue;
      if (distance + 1 >= dist[0][X][Y]) {
        continue;
      }

      vis[(X * 1000) + Y] = 1;
      parent[ {X, Y}] = {temp.first, temp.second};
      dist[1][X][Y] =  distance + 1;
      q.push({{X, Y}, distance + 1});
    }
  }
}

void bfsM(vector<pair<int, int>> M) {
  queue<pair<pair<int, int>, int>> q;

  for (auto it : M) {
    int x = it.first, y = it.second;
    q.push({{x, y}, 0});
    dist[0][x][y] = 0;
    vis[(x * 1000) + y] = 1;
  }



  while (!q.empty()) {
    pair<int, int> temp = q.front().first;
    int distance = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int X = temp.first + dx[i];
      int Y = temp.second + dy[i];
      if (!check(X, Y))
        continue;

      vis[ (X * 1000) + Y] = 1;
      dist[0][X][Y] =  distance + 1;
      q.push({{X, Y}, distance + 1});
    }
  }
}

void yash()
{
  cin >> n >> m;
  v.assign(n, vector<char>(m));
  dist[0].assign(n, vector<int>(m, 1000));
  dist[1].assign(n, vector<int>(m, 1000));
  vis.assign(1000010, 0);

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < m; j++) {
      v[i][j] = s[j];
    }
  }

  int ii, jj;
  vector<pair<int, int>> M;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'M') {
        M.push_back({i, j});
      }
      if (v[i][j] == 'A')ii = i, jj = j;
    }
  }
  bfsM(M);
  vis.assign(1000010, 0);
  bfs(ii, jj);


  // for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++) {
  //         cout << dist[0][i][j] << ' ';
  //     }
  //     cout << "\n";
  // }
  // cout << '\n';
  // for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++) {
  //         cout << dist[1][i][j] << ' ';
  //     }
  //     cout << "\n";
  // }


  if (gotIt == 0) {
    cout << "NO\n";
    return;
  }

  string ans = "";

  pair<int, int> curr = {ii, jj};
  if (curr.first == n - 1 || curr.second == m - 1 || curr.first == 0 || curr.second == 0) {
    cout << "YES\n";
    cout << "0\n";
    return;
  }
  curr = {iii, jjj};


  while (1) {
    pair<int, int> par = parent[curr];

    int x = par.first, y = par.second;

    if (x == curr.first) {
      if (y > curr.second) {
        ans += "L";
      }
      if (y < curr.second) {
        ans += "R";
      }
    }
    else {
      if (x < curr.first) {
        ans += "D";
      }
      if (x > curr.first) {
        ans += "U";
      }
    }

    if (x == ii && y == jj) {
      break;
    }

    curr = par;
  }
  reverse(all(ans));

  cout << "YES\n";
  cout << ans.size() << '\n';
  cout << ans << '\n';

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
