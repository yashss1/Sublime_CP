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
const int N = 1e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int adj[N][N];
int vis[N][N];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
        return false;
    if (vis[x][y])
        return false; // If visited returns false
    if(adj[x][y] != 0) return false;
    return true;
}

int dfs(int x, int y)
{
    vis[x][y] = 1; //As now visited marked to 1
    int ans = 1;   //As a cell is connected to itself
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (!check(X, Y)) //If Visited or outside boundary continue
            continue;
        ans += dfs(X, Y); // If not visited and inside boundary
    }
    return ans;
}

void yash()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for(int j = 0; j < m; j++) {
      adj[i][j] = s[j] == '.' ? 0 : 1;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(vis[i][j] == 0 && adj[i][j] == 0){
        dfs(i, j);
        ans++;
      }
    }
  }

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