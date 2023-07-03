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
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
*/

vector<pair<int, pair<int, int>>> adj;

// {
// DSU basic
int parent[N];
void make_set(int v) {
	parent[v] = v;
}
int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		parent[b] = a;
		// merge(a, b);
	}
}
// }

int n, m;
int kruskal() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	for (int i = 0; i < m; i++) {
		int x = adj[i].second.first;
		int y = adj[i].second.second;

		if (find_set(x) != find_set(y)) {
			ans += adj[i].first;
			union_sets(x, y);
		}
	}
	return ans;
}


void yash() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj.push_back({w, {a, b}});
	}
	sort(adj.begin(), adj.end());

	int ans = kruskal();
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