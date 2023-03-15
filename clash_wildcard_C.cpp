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

//1) Directions for checking whether a cell is valid or not
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int r, c;
vector<vector<int>> vis;
vector<vector<int>> v;

bool check(int x, int y, int curr)
{
    if (x < 0 || y < 0 || x >= r || y >= c) // Checking boundaries
        return false;
    if (v[x][y] != curr)
        return false; // If visited returns false
    return true;
}


void dfs(int x, int y) {
	int curr = v[x][y];
	v[x][y] = -1;
	for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (!check(X, Y, curr)) //If Visited or outside boundary continue
            continue;
        dfs(X, Y); // If not visited and inside boundary
    }

}

void yash()
{
  int n;
  cin >> n;
  cin >> r >> c;
  v.assign(r + 2, vector<int>(c + 2));
  for(int i = 0; i < r; i++) {
  	for(int j = 0; j < c; j++) {
  		cin >> v[i][j];
  	}
  }

  int m;
  cin >> m;
  vector<int> b(m);
  map<int, int> mp;
  for(int i = 0; i < m; i++) {
  	cin >> b[i];
  	mp[b[i]]++;
  }

  vector<int> ans(n + 2, 0);
  for(int i = 0; i < r; i++) {
  	for(int j = 0; j < c; j++) {
  		if(v[i][j] == -1) continue;
  		ans[v[i][j]]++;
  		dfs(i, j);
   	}
  }

  int anss = INT_MAX;
  for(int i = 1; i <= n; i++) {
  	if(ans[i] == 0) continue;
  	if(!mp[i]) continue;
  	anss = min(anss, ans[i]);
  }

  if(anss == INT_MAX) {
  	cout << "-1\n";
  	return;
  }

  cout << anss << '\n';

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