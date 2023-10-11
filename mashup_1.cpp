//YashS
// https://codeforces.com/gym/476638/problem/A

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

vector<int> adj[N];
vector<vector<int>> cycles;
vector<int> vis;
vector<int> currCycle;

void dfs(int node) {
	vis[node] = 1;
	currCycle.push_back(node);
	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs(it);
		}
	}
}

void yash()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	map<int, int> A, B, done;

	for (int i = 0; i < n + 2; i++) {
		adj[i].clear();
	}
	vis.assign(n + 2, 0);
	cycles.clear();

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		A[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		B[b[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (c[i] != 0) {
			done[c[i]] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		// for a[i]
		int onLineA = i, onLineB = B[a[i]];
		adj[onLineA].push_back(onLineB);
		adj[onLineB].push_back(onLineA);
	}

	// for (int i = 0; i < n; i++) {
	// cout << i << " -> ";
	// 	pVec(adj[i]);
	// }


	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			currCycle.clear();
			dfs(i);
			cycles.push_back(currCycle);
		}
	}

	int ans = 1;

	for (auto it : cycles) {
		pVec(it);
		set<int> st;
		for (auto ele : it) {
			st.insert(a[ele]);
			st.insert(b[ele]);
		}

		int flag = 2;
		if (st.size() < 2) flag = 1;
		for (auto it1 : st) {
			if (done[it1] == 1) {
				flag = 1;
			}
		}
		ans *= flag;
		ans %= MOD;
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