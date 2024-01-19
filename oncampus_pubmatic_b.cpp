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
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
Question:
For all nodes, print the 2nd adjacent node which occurs most of the times, if multiple print minium number wala

INPUT:
4
5 5
0 1
0 2
1 3
2 3
3 4
3 3
0 1
1 2
2 0
3 2
0 1
0 2
5 4
4 0
2 4
3 1
1 2

OUTPUT:
3 2 1 0 1
-1 -1 -1
-1 2 1
2 4 0 2 1

*/

vector<int> adj[100002];

int solve(int node) {
	map<int, int> mp, neighbours;
	for (auto it : adj[node]) {
		neighbours[it]++;
	}

	for (auto it : neighbours) {
		for (auto it1 : adj[it.first]) {
			if ((neighbours.find(it1) != neighbours.end()) || node == it1) continue;
			mp[it1]++;
		}
	}

	int mx = -1;
	for (auto it : mp) {
		mx = max(mx, it.second);
	}

	vector<int> ans;
	for (auto it : mp) {
		if (mx == it.second) {
			ans.push_back(it.first);
		}
	}

	sort(ans.begin(), ans.end());

	if (ans.size() == 0) {
		return -1;
	}

	return ans[0];
}

vector<int> getRecommendedFriendsByYashDontKnowIfCorrect(int n, vector<vector<int>> v) {
	int m = v.size();
	for (int i = 0; i < n + 2; i++) {
		adj[i].clear();
	}

	for (int i = 0; i < m; i++) {
		adj[v[i][0]].push_back(v[i][1]);
		adj[v[i][1]].push_back(v[i][0]);
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(solve(i));
	}
	return ans;
}


void yash()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	vector<int> ans = getRecommendedFriendsByYashDontKnowIfCorrect(n, v);
	pVec(ans);
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