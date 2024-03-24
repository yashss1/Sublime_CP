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

vector<int> adj[N];
int r = 0, b = 0;
vector<vector<int>> tempp;

void dfs(int node, int par, int lvl, int flag) {
	int curr = 0;
	for (auto it : adj[node]) {
		if (it != par) {
			// cout << node << " " << it << '\n';
			curr++;
		}
	}
	for (auto it : adj[node]) {
		if (it != par) {
			dfs(it, node, lvl + 1, (curr % 2 == 0) ? flag : flag ^ 1);
		}
	}
	r += (curr / 2), b += (curr / 2);
	// cout << node << " " << curr << '\n';
	if (curr % 2 == 0) return;
	if (flag) {
		r++;
	}
	else {
		b++;
	}
}


string ans;
void dfs2(int node, int par, int lvl, int flag) {
	int curr = 0;
	vector<int> temp;

	for (auto it : adj[node]) {
		if (it != par) {
			curr++;
			temp.push_back(it);
		}
	}
	for (auto it : adj[node]) {
		if (it != par) {
			dfs2(it, node, lvl + 1, (curr % 2 == 0) ? flag : flag ^ 1);
		}
	}

	for (int i = 1; i < temp.size(); i += 2) {
		ans[temp[i - 1] - 1] = 'R';
		ans[temp[i] - 1] = 'B';
	}


	// cout << node << " -> "; pVec(temp);

	if (temp.size() % 2 == 0) return;

	if (flag) {
		if (curr == 1) {
			tempp.push_back({lvl + 1, temp[temp.size() - 1], 0});
			return;
		}
		ans[temp[temp.size() - 1] - 1] = 'R';
	}
	else {
		if (curr == 1) {
			tempp.push_back({lvl + 1, temp[temp.size() - 1], 1});
			return;
		}
		ans[temp[temp.size() - 1] - 1] = 'B';
	}
}

void yash()
{
	int n;
	cin >> n;
	for (int i = 0; i < n + 2; i++) {
		adj[i].clear();
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int mn = INT_MAX;
	for (int i = 1; i <= n; i++) {
		r = 1, b = 0;
		dfs(i, -1, 0, 0);
		mn = min(mn, abs(r - b));
		// cout << r << " " << b << '\n';
	}


	for (int i = 1; i <= n; i++) {
		r = 1, b = 0;
		dfs(i, -1, 0, 0);
		if (abs(r - b) == mn) {
			string temp(n, '#');
			ans = temp;
			ans[0] = 'R';
			tempp.clear();
			tempp.push_back({0, i, 0});
			dfs2(i, -1, 0, 0);
			// cout << ans << '\n';

			int flag = 0;
			sort(all(tempp));
			vector<vector<int>> currr;
			currr.push_back(tempp[0]);

			// for (auto it : tempp) {
			// 	pVec(it);
			// } cout << "\n";
			for (int j = 1; j < tempp.size(); j++) {
				if (tempp[j - 1][0] + 1 == tempp[j][0]) {
					currr.push_back(tempp[j]);
				}
				else {
					if (currr.size() % 2 == 0) {
						for (int k = 0; k < currr.size() / 2; k++) {
							ans[currr[k][1] - 1] = 'R';
						}
						for (int k = currr.size() / 2; k < currr.size(); k++) {
							ans[currr[k][1] - 1] = 'B';
						}
					}
					else {
						if (flag) {
							for (int k = 0; k <= currr.size() / 2; k++) {
								ans[currr[k][1] - 1] = 'R';
							}
							for (int k = (currr.size() / 2) + 1; k < currr.size(); k++) {
								ans[currr[k][1] - 1] = 'B';
							}
						}
						else {
							for (int k = 0; k < currr.size() / 2; k++) {
								ans[currr[k][1] - 1] = 'R';
							}
							for (int k = currr.size() / 2; k < currr.size(); k++) {
								ans[currr[k][1] - 1] = 'B';
							}
						}
						flag ^= 1;
					}
					currr.clear();
				}
			}
			// for (auto it : currr) {
			// 	pVec(it);
			// }
			if (currr.size() % 2 == 0) {
				for (int k = 0; k < currr.size() / 2; k++) {
					ans[currr[k][1] - 1] = 'R';
				}
				for (int k = currr.size() / 2; k < currr.size(); k++) {
					ans[currr[k][1] - 1] = 'B';
				}
			}
			else {
				if (flag) {
					for (int k = 0; k <= currr.size() / 2; k++) {
						ans[currr[k][1] - 1] = 'R';
					}
					for (int k = (currr.size() / 2) + 1; k < currr.size(); k++) {
						ans[currr[k][1] - 1] = 'B';
					}
				}
				else {
					for (int k = 0; k < currr.size() / 2; k++) {
						ans[currr[k][1] - 1] = 'R';
					}
					for (int k = currr.size() / 2; k < currr.size(); k++) {
						ans[currr[k][1] - 1] = 'B';
					}
				}
				flag ^= 1;
			}

			cout << ans << '\n';
			break;
		}
	}
	// cout << mn << '\n';
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