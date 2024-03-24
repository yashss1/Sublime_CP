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

int n, k;
vector<int> adj[N];
vector<int> subTreeSize(N), subTreeSizeD;
vector<int> mxHeight(N);

int part = 0;
int helper(int node, int par, int x) {
	int curr = 1;
	for (auto it : adj[node]) {
		if (it != par) {
			curr += helper(it, node, x);
		}
	}
	subTreeSize[node] = curr;
	if (node != 1 && subTreeSize[node] >= x) {
		part++;
		curr = 0;
	}
	return curr;
}

vector<int> currPar;
int root;
int dfs(int node, int par, int x) {
	int curr = 0, currr = 0;
	for (auto it : adj[node]) {
		if (it != par) {
			curr = dfs(it, node, x);
			subTreeSizeD[node] -= curr;
			currr += curr;
			if (subTreeSizeD[it] >= x) {
				// cout << node << " " << it << "|||| " << subTreeSizeD[node] << " " << subTreeSizeD[it] << "\n";
				if (node == root && (subTreeSizeD[node] - subTreeSizeD[it] >= x)) {
					part++;
					subTreeSizeD[node] -= subTreeSizeD[it];
					currr += (subTreeSizeD[it]);
					currPar.push_back(it);
				}
				else if (node != root) {
					part++;
					subTreeSizeD[node] -= subTreeSizeD[it];
					currr += (subTreeSizeD[it]);
					currPar.push_back(it);
				}
			}
		}
	}
	// cout << " node : " << node << " " << currr << '\n';
	return currr;
}

bool solve(int x) {
	subTreeSizeD = subTreeSize;
	part = 0;
	currPar.clear();
	currPar.push_back(root);
	dfs(root, -1, x);

	// cout << "CurrPAR : ";
	// pVec(currPar);
	// for (int i = 1; i <= n; i++) {
	// 	cout << "sub : " << i << " " << subTreeSizeD[i] << '\n';
	// }

	int flag = 1;
	for (auto it : currPar) {
		if (subTreeSizeD[it] < x) {
			flag = 0;
		}
	}

	// cout << flag << " | " << part << '\n';
	if (flag == 0 || part < k) {
		return 0;
	}
	// cout << x << " " << part << '\n';
	return 1;
}

void yash()
{
	cin >> n >> k;
	for (int i = 0; i < n + 5; i++) {
		adj[i].clear();
	}
	subTreeSize.assign(n + 1, 0);
	mxHeight.assign(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// root = 1;
	// int mn = INT_MAX;
	// for (int i = 1; i <= n; i++) {
	// 	subTreeSize.assign(n + 1, 0);
	// 	helper(i, -1);
	// 	int mx = 0;
	// 	for (auto it : adj[i]) {
	// 		mx = max(mx, subTreeSize[it] + 1);
	// 	}
	// 	if (mx < mn) {
	// 		mn = mx;
	// 		root = i;
	// 	}
	// }

	// // cout << root << " " << mn << "\n";
	// subTreeSize.assign(n + 1, 0);
	// helper(root, -1);


	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " -> " << subTreeSize[i] << '\n';
	// 	// solve(i);
	// }
	// for (int i = 3; i <= 3; i++) {
	// 	// cout << i << " -> " << subTreeSize[i] << '\n';
	// 	if (solve(i)) {
	// 		cout << "HEHE " << i << '\n';
	// 	}

	// }

	int l = 0, r = n - 1, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		part = 0;
		subTreeSize.assign(n + 1, 0);
		helper(1, -1, mid);
		// cout << mid << " -> " << part << " -> ";
		// pVec(subTreeSize);

		int flag = 1;
		if (part < k) {
			flag = 0;
		}
		else if (part == k && subTreeSize[1] < mid) {
			flag = 0;
		}

		if (flag || part > k) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
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