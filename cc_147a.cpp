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
const int N = 2e5 + 7;
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m;
map<pair<int, int>, int> vis;
map<pair<int, int>, pair<int, int>> parent;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<char>> v;
vector<vector<int>> dist[2];


bool check(int x, int y, int curr_distance, int flag)
{
	if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
		return false;
	if (vis[ {x, y}] == 1)
		return false; // If visited returns false
	if (v[x][y] == '#') return false;
	if (dist[flag][x][y] < curr_distance)return false;
	return true;
}

void bfs(int x, int y, int flag) { //flag = 0, bfs for M else bfs for A
	queue<pair<pair<int, int>, int>> q; // {x, y, distance from root}
	vector<pair<int, int>> visited;

	q.push({{x, y}, 0});
	dist[flag][x][y] = 0;
	vis[ {x, y}] = 1;
	visited.push_back({x, y});

	while (!q.empty()) {
		pair<int, int> temp = q.front().first;
		int distance = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = temp.first + dx[i];
			int Y = temp.second + dy[i];
			if (!check(X, Y, distance + 1, flag))
				continue;

			vis[ {X, Y}] = 1;
			visited.push_back({X, Y});
			parent[ {X, Y}] = {temp.first, temp.second};
			dist[flag][X][Y] =  distance + 1;
			q.push({{X, Y}, distance + 1});
		}
	}

	for (int i = 0; i < visited.size(); i++) {
		vis[ {visited[i].first, visited[i].second}] = 0;
	}
}

void bfsM(vector<pair<int, int>> M) {
	vector<pair<int, int>> visited;
	queue<pair<pair<int, int>, int>> q;

	for (auto it : M) {
		int x = it.first, y = it.second;
		q.push({{x, y}, 0});
		dist[0][x][y] = 0;
		vis[ {x, y}] = 1;
		visited.push_back({x, y});
	}



	while (!q.empty()) {
		pair<int, int> temp = q.front().first;
		int distance = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = temp.first + dx[i];
			int Y = temp.second + dy[i];
			if (!check(X, Y, distance + 1, 0))
				continue;

			vis[ {X, Y}] = 1;
			visited.push_back({X, Y});
			parent[ {X, Y}] = {temp.first, temp.second};
			dist[0][X][Y] =  distance + 1;
			q.push({{X, Y}, distance + 1});
		}
	}

	for (int i = 0; i < visited.size(); i++) {
		vis[ {visited[i].first, visited[i].second}] = 0;
	}
}

void yash()
{
	cin >> n >> m;
	v.assign(n, vector<char>(m));
	dist[0].assign(n, vector<int>(m, 1000));
	dist[1].assign(n, vector<int>(m, 1000));

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
	bfs(ii, jj, 1);

	// for(int i = 0; i < n; i++) {
	//   for(int j = 0; j < m; j++) {
	//     cout << dist[0][i][j] << ' ';
	//   }
	//   cout << "\n";
	// }
	// cout << '\n';
	// for(int i = 0; i < n; i++) {
	//   for(int j = 0; j < m; j++) {
	//     cout << dist[1][i][j] << ' ';
	//   }
	//   cout << "\n";
	// }


	int gotIt = 0, iii, jjj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (dist[0][i][j] > dist[1][i][j]) {
					iii = i, jjj = j;
					gotIt = 1;
					goto end;
				}
			}
		}
	}

end:
	if (gotIt == 0) {
		cout << "NO\n";
		return;
	}


	if (ii == iii && jj == jjj) {
		cout << "YES\n0\n";
		return;
	}

	string ans = "";
	pair<int, int> curr = {iii, jjj};
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
