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
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
3
3 3
0 1 2
0 2 1
1 2 0
4 3
2 0 1
0 2 1
0 1 2
2 1 0
5 4
0 1 3 2
0 2 3 1
1 0 3 2
2 1 0 3
0 3 1 2

ANS
0 1 2
0 2 1
0 1 3 2
*/

vector<int> adj[N];
vector<int> vis(N);
vector<int> ans;
int n, m;

void clr(int m) {
	for (int i = 0; i < m + 5; i++) {
		adj[i].clear();
	}
	vis.clear();
	vis.assign(m + 1, 0);
	ans.clear();
}


void topo(vector<int> &inDegree) {
	queue<int> q;
	for (int i = 0; i < m; i++) {
		if (inDegree[i] == 0) {
			ans.push_back(i);
			q.push(i);
		}
	}

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (auto it : adj[t]) {
			inDegree[it]--;
			if (inDegree[it] == 0) {
				ans.push_back(it);
				q.push(it);
			}
		}
	}
}

void yash()
{
	cin >> n >> m;
	clr(m);
	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<int>> res(m, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				res[v[i][j]][v[i][k]]++;
			}
		}
	}

	vector<vector<int>> res1;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			// cout << i << " " << j << " -> " << res[i][j] << '\n';
			if (res[i][j] >= res[j][i]) {
				res1.push_back({res[i][j], i, j});
			}
			else {
				res1.push_back({res[j][i], j, i});
			}
		}
	}

	sort(res1.begin(), res1.end());
	reverse(res1.begin(), res1.end());

	vector<int> inDegree(m, 0);
	for (auto it : res1) {
		// cout << it[0] << " -> " << it[1] << " " << it[2] << '\n';
		adj[it[1]].push_back(it[2]);
		inDegree[it[2]]++;
	}

	topo(inDegree);
	pVec(ans);
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