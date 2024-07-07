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
Infosys 7july 2024, naman friend

6 4 5
0 1 1 2 3 3
7
1
5
0 1 1 2 3 3 3

*/

int n, a, b;
vector<int> adj[N], subTreeSize(N);
vector<vector<pair<int, int>>> mainChildren(N);

int dfs(int node, int par) {
	int sum = 0;
	if (node == a)sum++;
	if (node == b)sum++;
	for (auto it : adj[node]) {
		if (it != par) {
			int val = dfs(it, node);
			sum += val;
			if (val != 0) {
				mainChildren[node].push_back({val, subTreeSize[it]});
			}
		}
	}
	return sum;
}

int subTree(int node, int par) {
	int sum = 1;
	for (auto it : adj[node]) {
		if (it != par) {
			sum += subTree(it, node);
		}
	}
	subTreeSize[node] = sum;
	return sum;
}

void yash()
{
	cin >> n >> a >> b;
	for (int i = 0; i <= n; i++) {
		mainChildren[i].clear();
		adj[i].clear();
	}
	subTreeSize.assign(n + 1, 0);

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0)continue;
		adj[i + 1].push_back(v[i]);
		adj[v[i]].push_back(i + 1);
	}

	subTree(1, 0);
	dfs(1, 0);

	// pVec(subTreeSize);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// cout << i << " -> ";
		// for (auto it : mainChildren[i]) {
		//     cout << it.first << " " << it.second << '\n';
		// }

		int curr = 0;
		if (mainChildren[i].size() == 0) {
			curr += 1;
		}
		else if (mainChildren[i].size() == 2) {
			curr += (n - (mainChildren[i][0].second + mainChildren[i][1].second));
		} else if (mainChildren[i].size() == 1) {
			// one with self ?? -> other part
			// else 1

			if (i == a || i == b) {
				curr += (n - mainChildren[i][0].second);
			} else {
				curr += (n - ((n - subTreeSize[i]) + (mainChildren[i][0].second)));
			}
		}

		// cout << curr << "\n\n";
		ans += curr;
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