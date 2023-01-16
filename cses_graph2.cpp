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

char adj[N][N];
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
    if(adj[x][y] == '#') return false;
    return true;
}

void yash()
{
  cin >> n >> m;
  int ii, jj, iif, jjf;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for(int j = 0; j < m; j++) {
      adj[i][j] = s[j];
      if(s[j] == 'A') {
      	ii = i;
      	jj = j;
      }
      if(s[j] == 'B') {
        iif = i;
        jjf = j;
      }
    }
  }

  queue<pair<int,int>> q;
  q.push({ii, jj});
  map<pair<int,int>, pair<int,int>> parent;  // gives parent of i, j
  int gotB = 0;

  while(!q.empty()){
  	pair<int, int> node = q.front();
  	q.pop();
    int x = node.first, y = node.second;

    if(x == iif && y == jjf){
        gotB = 1;
        break;
    }

  	// cout << x << ' ' << y << '\n';

    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (!check(X, Y)) 
            continue;
        parent[{X, Y}] = {x, y};
        vis[X][Y] = 1;
        // cout << X << " " << Y << '\n';
        q.push({X, Y});
    }
  }

  if(gotB == 0) {
    cout << "NO\n";
    return;
  }

  string ans = "";
  pair<int, int> curr = {iif, jjf};
  int t = 10;
  while(1) {
    pair<int, int> par = parent[curr];
    int x = par.first, y = par.second;

    if (x == curr.first) {
        if(y > curr.second) {
            ans += "L";
        }
        if(y < curr.second) {
            ans += "R";
        }
    }
    else {
        if(x < curr.first) {
            ans += "D";
        }
        if(x > curr.first) {
            ans += "U";
        }
    }

    if(x == ii && y == jj) {
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