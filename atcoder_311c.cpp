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

vector<vector<int>> adj;
vector<int> res;
int flag = 0;

void dfs(int node, int start, int thiss) {
	if (thiss == 0) {
		if (start == node) {
			flag = 1;
			return;
		}
	}
	if (flag == 0)
		res.push_back(node);
	for (auto it : adj[node]) {
		dfs(it, start, 0);
		if (flag == 1) return;
	}
}

bool isCyclic(int V) {
	vector<int> inDegree(V + 1, 0); // stores in-degree of each vertex
	queue<int> q; // queue to store vertices with 0 in-degree
	int visited = 0; // count of visited vertices

	// calculate in-degree of each vertex
	for (int u = 1; u <= V; u++) {
		for (auto v : adj[u]) {
			inDegree[v]++;
		}
	}

	// enqueue vertices with 0 in-degree
	for (int u = 1; u <= V; u++) {
		if (inDegree[u] == 0) {
			q.push(u);
		}
	}

	// BFS traversal
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		visited++;

		// reduce in-degree of adjacent vertices
		for (auto v : adj[u]) {
			inDegree[v]--;
			// if in-degree becomes 0, enqueue the vertex
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (inDegree[i] != 0) {
			if (flag == 0)
				dfs(i, i, 1);
		}
	}

	return visited != V; // if not all vertices are visited, there is a cycle
}


void yash()
{
	int n;
	cin >> n;
	adj.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		adj[i].push_back(a);
	}

	flag = 0;
	res.clear();
	isCyclic(n);

	cout << res.size() << '\n';
	for (auto it : res) {
		cout << it << " ";
	}
	cout << '\n';
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}