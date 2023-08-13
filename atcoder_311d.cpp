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

//1) Directions for checking whether a cell is valid or not
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

//3) In DFS we need to map what is visited and what is not, which reduces time compexity as well as double counting.
vector<vector<int>> vis;
//2) checking, that it doesnt go outside the boundary
int n, m;
bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
		return false;
	if (vis[x][y] == -1) {
		return false;
	}
	if (vis[x][y] > 10)
		return false; // If visited returns false
	return true;
}
int dfs(int x, int y, int dir, int xx, int yy)
{
	if (x == 14 && y == 14) {
		cout << "ASDS\n";
	}
	if (x == 9 && y == 13) {
		cout << "asdasdas\n";
	}
	if (x == 9 && y == 23) {
		cout << "qwess\n";
	}
	vis[x][y] = 1; //As now visited marked to 1
	int ans = 1;   //As a cell is connected to itself

	int X = x + dx[dir];
	int Y = y + dy[dir];

	if (check(X, Y)) {
		dfs(X, Y, dir, x, y);
	}
	else {

		for (int i = 0; i < 4; i++)
		{

			int X = x + dx[i];
			int Y = y + dy[i];
			if (X == xx && Y == yy) continue;
			if (!check(X, Y)) //If Visited or outside boundary continue
				continue;
			ans += dfs(X, Y, i, x, y); // If not visited and inside boundary
		}
	}

	return ans;
}


void yash()
{
	cin >> n >> m;
	vis.clear();
	vis.resize(n, vector<int>(m)); //Making matrix of n*m
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == '#') {//Marking already visited
				vis[i][j] = 1;
			}
			else {
				res++;
			}
		}
	}

	// for (int i = 1; i <= 1; i++) {
	// 	dfs(1, 1, i - 1, -1, -1);
	// }

	// int ans = 0;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << vis[i][j] << " ";
	// 		if (vis[i][j] == 0) {
	// 			ans++;
	// 		}
	// 	}
	// 	cout << '\n';
	// }

	// // cout << res << '\n';
	// cout << (res - ans) << '\n';



	queue<vector<int>> q; // node dir
	q.push({1, 1, 0});
	q.push({1, 1, 1});
	q.push({1, 1, 2});
	q.push({1, 1, 3});

	while (q.empty()) {
		vector<int> temp = q.front();
		q.pop();

		int x = temp[0], y = temp[1];
		vis[x][y] = 1;

		int X = x + dx[temp[2]];
		int Y = y + dy[temp[2]];

		int xx = x, yy = y;
		while (check(X, Y) == 1) {
			xx = X, yy = Y;
			X += dx[temp[2]];
			Y += dy[temp[2]];
		}
		xx -= dx[temp[2]];
		yy -= dy[temp[2]];

		// cout << x << " " << y << " | " << xx << " " << yy << "\n";

		if (temp[2] == 0) {
			for (int i = 0; i < 4; i++) {
				if (i == 3)continue;
				if (check(xx + dx[i], yy + dy[i])) {
					q.push({xx, yy, i});
				}
			}
		}
		if (temp[2] == 1) {
			for (int i = 0; i < 4; i++) {
				if (i == 2)continue;
				if (check(xx + dx[i], yy + dy[i])) {
					q.push({xx, yy, i});
				}
			}
		}
		if (temp[2] == 2) {
			for (int i = 0; i < 4; i++) {
				if (i == 1)continue;
				if (check(xx + dx[i], yy + dy[i])) {
					q.push({xx, yy, i});
				}
			}
		}
		if (temp[2] == 3) {
			for (int i = 0; i < 4; i++) {
				if (i == 0)continue;
				if (check(xx + dx[i], yy + dy[i])) {
					q.push({xx, yy, i});
				}
			}
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vis[i][j] << " ";
		}
		cout << '\n';
	}
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