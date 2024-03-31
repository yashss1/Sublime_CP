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
7
10 9 8 8 2 7 4
1 2
1 3
1 4
2 5
2 6
2 7
*/

vector<int> adj[N];
vector<int> v, subTreeSum;
int totalSum = 0;

int findSubtreeSum(int node, int par) {
	int sum = v[node - 1];
	totalSum += v[node - 1];
	totalSum %= MOD;
	for (auto it : adj[node]) {
		if (it != par) {
			sum += findSubtreeSum(it, node);
			sum %= MOD;
		}
	}
	return subTreeSum[node] = sum;
}

vector<int> ans;
void dfs(int node, int par) {
	int childSum = subTreeSum[node] - v[node - 1];
	childSum = (childSum + MOD) % MOD;
	int parSum = 0, sum = 0;
	if (par != -1) {
		parSum = totalSum - subTreeSum[node];
		parSum = (parSum + MOD) % MOD;
		parSum %= MOD;
	}
	sum += ((parSum * childSum) % MOD);
	sum %= MOD;

	int done = 0;
	for (auto it : adj[node]) {
		if (it != par) {
			int remSum = childSum - subTreeSum[it] - done;
			remSum = (remSum + MOD) % MOD;
			done += subTreeSum[it];
			done %= MOD;
			sum += ((subTreeSum[it] * remSum) % MOD);
			sum %= MOD;
			dfs(it, node);
		}
	}

	ans[node - 1] = sum;
}

void yash()
{
	int n;
	cin >> n;
	v.assign(n, 0);
	ans.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	subTreeSum.assign(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	totalSum = 0;
	findSubtreeSum(1, -1);
	dfs(1, -1);

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " -> " << subTreeSum[i] << '\n';
	// }

	pVec(ans);
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