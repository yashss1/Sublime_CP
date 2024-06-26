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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//3) In DFS we need to map what is visited and what is not, which reduces time compexity as well as double counting.
vector<vector<int>> vis, vis2;
vector<vector<pair<int, int>>>hehe;
//2) checking, that it doesnt go outside the boundary
int n, m;
bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
		return false;
	if (vis[x][y])
		return false; // If visited returns false
	return true;
}
bool check2(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
		return false;
	if (vis2[x][y])
		return false; // If visited returns false
	return true;
}

int dfs(int x, int y) {
	vis[x][y] = 1; //As now visited marked to 1
	int ans = 1;   //As a cell is connected to itself
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (!check(X, Y)) //If Visited or outside boundary continue
			continue;
		ans += dfs(X, Y); // If not visited and inside boundary
	}
	return ans;
}
void dfs2(int x, int y, int putHere, int grpId) {
	vis2[x][y] = 1;
	hehe[x][y].first = putHere;
	hehe[x][y].second = grpId;
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (!check2(X, Y))
			continue;
		dfs2(X, Y, putHere, grpId);
	}
}

void yash() {
	cin >> n >> m;
	vis.clear();
	vis.resize(n, vector<int>(m));
	vis2.clear();
	vis2.resize(n, vector<int>(m));
	hehe.clear();
	hehe.assign(n, vector<pair<int, int>>(m, {0, 0}));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '.') {
				vis[i][j] = 1;
				vis2[i][j] = 1;
			}
		}
	}

	vector<int> sizes;
	int grpId = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check(i, j)) {
				int temp = dfs(i, j);
				dfs2(i, j, temp, grpId);
				grpId++;
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << hehe[i][j].first << "," << hehe[i][j].second  << " ";
	// 	} cout << "\n";
	// }

	int ans = 0;

	// iterate over all rows
	for (int i = 0; i < n; i++) {
		set<pair<int, int>> st;
		if (i != 0) {
			for (int j = 0; j < m; j++) {
				if (hehe[i - 1][j].first != 0)
					st.insert({hehe[i - 1][j].first, hehe[i - 1][j].second});
			}
		}
		if (i != n - 1) {
			for (int j = 0; j < m; j++) {
				if (hehe[i + 1][j].first != 0)
					st.insert({hehe[i + 1][j].first, hehe[i + 1][j].second});
			}
		}
		int res = 0;
		for (int j = 0; j < m; j++) {
			if (hehe[i][j].first != 0)
				st.insert({hehe[i][j].first, hehe[i][j].second});
			if (hehe[i][j].first == 0) {
				res++;
			}
		}
		for (auto it : st) {
			res += (it.first);
		}
		ans = max(ans, res);
	}

	// iterate over all cols
	for (int i = 0; i < m; i++) {
		set<pair<int, int>> st;
		if (i != 0) {
			for (int j = 0; j < n; j++) {
				if (hehe[j][i - 1].first != 0)
					st.insert({hehe[j][i - 1].first, hehe[j][i - 1].second});
			}
		}
		if (i != m - 1) {
			for (int j = 0; j < n; j++) {
				if (hehe[j][i + 1].first != 0)
					st.insert({hehe[j][i + 1].first, hehe[j][i + 1].second});
			}
		}
		int res = 0;
		for (int j = 0; j < n; j++) {
			if (hehe[j][i].first != 0)
				st.insert({hehe[j][i].first, hehe[j][i].second});
			if (hehe[j][i].first == 0) {
				res++;
			}
		}
		for (auto it : st) {
			res += (it.first);
		}
		ans = max(ans, res);
	}

	cout << ans << '\n';
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