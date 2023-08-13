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
int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int go(int node, vector<int> &price, vector<int>&fixPrice, vector<vector<int>> &adj) {
	if (fixPrice[node] != -1) {
		return fixPrice[node];
	}

	int curr = 0;
	for (auto it : adj[node]) {
		int t = go(it, price, fixPrice, adj);
		// cout << node << " " << it << " -- " << t << " it go(it)\n";
		curr += t;
	}

	fixPrice[node] = min(price[node], curr);
	// cout << node << " -> " << curr << "||\n";
	return fixPrice[node];
}

void yash()
{
	int n, k;
	cin >> n >> k;
	vector<int> price(n + 1), fixPrice(n + 1, -1);
	vector<vector<int>> adj;

	for (int i = 1; i <= n; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		price[a] = 0;
	}

	adj.resize(n + 5);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int a; cin >> a;
			adj[i].push_back(a);
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " -> ";
	// 	pVec(adj[i]);
	// }

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 0)
			fixPrice[i] = price[i];
	}

	// pVec(fixPrice);
	for (int i = 1; i <= n; i++) {
		go(i, price, fixPrice, adj);
	}

	// pVec(fixPrice);

	for (int i = 1; i <= n; i++) {
		cout << fixPrice[i] << " ";
	}
	cout << "\n";
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
