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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> adj[N];

void yash()
{
	int n;
	cin >> n;
	for (int i = 0; i < n + 2; i++) {
		adj[i].clear();
	}

	vector<int> inDegree(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			adj[x].push_back(i + 1);
			inDegree[i + 1]++;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " -> ";
	// 	pVec(adj[i]);
	// }

	// pVec(inDegree);

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> topo;
	map<int, int> taken;

	vector<int> remainders;

	while (!q.empty()) {
		int node = q.top();
		q.pop();
		topo.push_back(node);

		for (auto it : adj[node]) {
			inDegree[it]--;
			if (inDegree[it] == 0) {
				if (it <= node) {
					remainders.push_back(it);
				}
				else {
					q.push(it);
				}
			}
		}

		if (q.empty()) {
			for (auto it : remainders) {
				q.push(it);
			}
			remainders.clear();
		}
	}

	// pVec(topo);
	if (topo.size() != n) {
		cout << "-1\n";
		return;
	}

	int ans = 1;
	for (int i = 1; i < topo.size(); i++) {
		if (topo[i - 1] > topo[i]) {
			ans++;
		}
	}

	cout << ans << "\n";
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