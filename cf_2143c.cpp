//naman
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> adj[N];

void naman()
{
	int n;
	cin >> n;
	vector<int> inDegree(n + 1);

	for (int i = 0; i <= n; i++) {
		adj[i].clear();
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		if (y >= x) {
			adj[v].push_back(u);
			inDegree[u]++;
		} else {
			adj[u].push_back(v);
			inDegree[v]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> ans(n);
	int k = n;

	while (!q.empty()) {
		int curr = (int)q.front();
		ans[curr - 1] = k--;
		q.pop();
		for (auto it : adj[curr]) {
			inDegree[it]--;
			if (inDegree[it] == 0) {
				q.push(it);
			}
		}
	}

	pVec(ans);

}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	naman();
	return 0;
}