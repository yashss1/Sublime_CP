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

int n, m;
vector<vector<char>> adj;
vector<vector<int>> vis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

string S = "snuke";

bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
		return false;
	if (vis[x][y])
		return false; // If visited returns false
	return true;
}

int dfs(int x, int y, int ch) {
	// cout << x << " " << y << '\n';
	vis[x][y] = 1;
	if (x == n - 1 && y == m - 1) {
		return 1;
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (!check(X, Y))
			continue;
		if (adj[X][Y] == S[ch % 5]) {
			ans |= dfs(X, Y, ch + 1);
		}
	}
	return ans;
}

void yash()
{
	cin >> n >> m;
	adj.assign(n, vector<char>(m));
	vis.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			adj[i][j] = s[j];
		}
	}

	// for (int i = 0; i < n; i++) {
	//     for (int j = 0; j < m; j++) {
	//         cout << adj[i][j] << " ";
	//     }
	//     cout << '\n';
	// }

	int ans = (adj[0][0] == 's') ? dfs(0, 0, 1) : 0;

	if (ans == 1) {
		cout << "Yes\n";
		return;
	}

	cout << "No\n";
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