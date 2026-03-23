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
int ans = 0;
vector<int> vis;
int stop = 0;
set<int> st;

void go(int node, int direction) {
	st.insert(node);
	// if this is inward, all its neighbour should be outward
	for (auto it : adj[node]) {
		int wantDirection = (direction == 1 ? 2 : 1);
		if (vis[it] != 0) {
			if (vis[it] != wantDirection) {
				stop = 1;
			}
		}
		if (vis[it] == 0) {
			vis[it] = wantDirection;
			go(it, wantDirection);
		}
	}
}

void markRedBlack(int node, int curr) {
	return;
}

void yash()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 5; i++) {
		adj[i].clear();
	}
	vis.assign(n + 2, 0);
	// 0 - not assigned
	// 1 - inward
	// 2 - outward

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// if (m == 0) {
	// 	cout << n << '\n';
	// 	return;
	// }

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " -> " << adj[i].size() << '\n';
	// } cout << '\n';


	int ans = 0;
	for (int i = 1; i <= n; i++) {
		stop = 0;
		st.clear();
		if (vis[i] == 0) {
			go(i, 2);
		}
		// cout << i << " -> " << st.size() << " " << stop << '\n';
		if (stop == 0) {
			// nice
			map<int, int> mp;
			for (auto it : st) {
				// cout << it << " " << vis[it] << "\n";
				mp[vis[it]]++;
			}
			ans += (max(mp[1], mp[2]));

			if (st.size() == 1) {
				ans++;
			}
			// cout << '\n';
		}
		else {
			// not nice
			// cout << i << " " << "-1\n";
			// pVec(st);
		}
	}

	// cout << '\n';

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