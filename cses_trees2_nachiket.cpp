/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 28 January 2023 05:07:41 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;
 
#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif
 
const int MX = 2e5 + 5;
int N;
vector<int> g[MX];
int dp[2][MX];
 
int go(int curr, int parent, bool counted_already) {
	int& ans = dp[counted_already][curr];
	if (~ans)
		return ans;
	ans = 0;
	int block2 = 0;
	// maybe precompute this
	for (const int& child : g[curr])
		if (child != parent) {
			block2 += go(child, curr, false);
		}
	for (const int& child : g[curr]) {
		if (child ^ parent) {
			// choice 1: use this edge
			if (!counted_already) {
				/* block1 */
				// what does this block compute?
				// 1 + go(child, curr, true) + go(other_child, curr, false)
				// how can we optimize calculating this?
				// first 2 terms are computed in single calls
				// 3rd term is an iteration
				// go(other_child, curr, false) can be framed as { go(all_children, curr, false) - go(child, curr, false) }?
				int c1 = 1 + go(child, curr, true);
				// int add = 0; // any way to optimize computing `add`?
				// for (int other_child : g[curr]) {
				// 	if (other_child != parent && other_child != child) {
				// 		add += go(other_child, curr, false);
				// 	}
				// }
				int add = block2 - go(child, curr, false);
				ans = max(ans, c1 + add);
			}
 
			// choice 2: don't use this edge
			// {
			/* block2 */
			// this block just computes go($child, curr, false) over all children of node `curr`
			// int c2 = 0 + go(child, curr, false);
			// int add = 0; // any way to optimize computing `add`?
			// for (int other_child : g[curr]) {
			// 	if (other_child != parent && other_child != child) {
			// 		add += go(other_child, curr, false);
			// 	}
			// }
			// ans = max(ans, c2 + add);
			// }
			// block2 += go(child, curr, false);
		}
	}
	ans = max(ans, block2);
	return ans;
}
 
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << max(go(1, 1, true), go(1, 1, false)) << '\n';
 
	return 0;
}