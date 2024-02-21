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

int n;
vector<int> adj[N];
string s;
int ans = 0;

vector<vector<int>> dp;

int dfs(int node, int par, int party) {
	int child = 0;

	int &ans = dp[party][node];
	if (ans != -1) {
		return ans;
	}

	ans = 0;

	for (auto it : adj[node]) {
		int c1 = INT_MAX, c2 = INT_MAX;
		if (it != par) {
			child++;
			if (s[it - 1] == 'S') {
				int curr = 0;
				if (party == 1) {
					curr++;
				}
				c1 = curr + dfs(it, node, 0);
			}

			if (s[it - 1] == 'P') {
				int curr = 0;
				if (party == 0) {
					curr++;
				}
				c1 = curr + dfs(it, node, 1);
			}

			if (s[it - 1] == 'C') {
				c1 = dfs(it, node, party);
				c2 = 1 + dfs(it, node, party ^ 1);
			}

			ans += min({c1, c2});
		}
	}
	if (child == 0) {
		return 0;
	}

	// cout << node << " " << c1 << " " << c2 << '\n';
	return ans;
}

void yash()
{
	cin >> n;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
	}

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	cin >> s;

	dp.assign(2, vector<int>(n + 5, -1));

	int res = INT_MAX;
	if (s[0] == 'C') {
		int c1 = dfs(1, 0, 0);
		int c2 = dfs(1, 0, 1);
		res = min(c1, c2);
	}
	else {
		int ans = dfs(1, 0, s[0] == 'P' ? 1 : 0);
		res = min(res, ans);
	}

	cout << res << '\n';
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