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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
vector<vector<int>> vis, fall, block;

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
        return false;
    if (vis[x][y])
        return false; // If visited returns false
    return true;
}


int flag = 0;
void dfs(int x, int y)
{
	if(flag == 1) {
		return;
	}
	x = fall[x][y];
	if(x == n - 1) {
		return;
	}
	if(vis[x][y] == 1) {
		return;
	}
	vis[x][y] = 1; //As now visited marked to 1
	if(x == n - 2 && y == m - 1) {
		flag = 1;
		return;
	}
	// cout << x + 1 << " " << y + 1 << "\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     int X = x + dx[i];
    //     int Y = y + dy[i];
    //     if (!check(X, Y)) 
    //         continue;
    //     int c1 = (y > 0 && vis[x][y - 1] == 0); // check j - 1
    //     int c2 = (y < m && vis[x][y + 1] == 0); // check j - 1
    //     // int c3 = solve(x, y); // check i - 1, j - 1
    //     // int c4 = solve(x, y); // check i - 2, j - 1

    //     ans += dfs(X, Y);
    // }

    if(check(x, y - 1)) {
		dfs(x, y - 1);    	
    }
    if(check(x, y + 1)) {
		dfs(x, y + 1);    	
    }
    
    if(check(x - 1, y)) {
    	if(check(x - 1, y + 1)) {
    		dfs(x - 1, y + 1);
    	}
    }
    if(check(x - 1, y)) {
    	if(check(x - 1, y - 1)) {
    		dfs(x - 1, y - 1);
    	}
    }

    if(check(x - 1, y) && check(x - 2, y)) {
    	if(check(x - 2, y - 1)) {
    		dfs(x - 2, y - 1);
    	}
    }
    if(check(x - 1, y) && check(x - 2, y)) {
    	if(check(x - 2, y + 1)) {
    		dfs(x - 2, y + 1);
    	}
    }

    return;
}

void yash()
{
  	cin >> n >> m;
    vis.clear();
    flag = 0;
    vis.resize(n, vector<int>(m));
    block.resize(n, vector<int>(m));
    fall.resize(n, vector<int>(m)); 
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '*') { //Marking already visited
                vis[i][j] = 1;
                block[i][j] = 1;
            }
        }
    }

    vector<int> temp(m, n);
    for(int i = n - 1; i >= 0; i--) {
    	for(int j = m - 1; j >= 0; j--) {
    		if(vis[i][j] == 1) {
    			temp[j] = i;
    		}
    		fall[i][j] = temp[j] - 1; 	
    	}
    }

    // for(int i = 0; i < n; i++) {
    // 	for(int j = 0; j < m; j++) {
    // 		cout << fall[i][j] << " "; 
    // 	}
    // 	cout << "\n";
    // }
    // cout << '\n';

    dfs(n - 2, 0);

    if(flag == 1) {
    	cout << "Princess Saved\n";
    	return;
    }

    cout << "Princess Died\n";
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