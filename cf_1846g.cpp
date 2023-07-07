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

int n, m;
vector<int> adj[N];
vector<int> v;
string s;
vector<int> vis(N);
int ans;
vector<pair<string, string>> res;

void dfs(int node, int ress, string ss, int prev) {
	int fl = 0;
	for (int i = 0; i < n; i++) {
		if (ss[i] == '1') {
			fl = 1;
		}
	}
	if (fl == 0) {
		ans = min(ans, ress);
	}

	for (auto it : adj[node]) {
		if (it != prev) {
			string temp = ss;
			for (int i = 0; i < n; i++) {
				if (ss[i] == res[it].first[i] && ss[i] == '1') {
					temp += "0";
				}
				else if (ss[i] == '1') {
					temp += "1";
				}
				else {
					temp += "0";
				}
			}
			dfs(it, ress + v[node], temp, node);
		}
	}
}

void yash()
{

	cin >> n >> m;
	cin >> s;
	ans = INT_MAX;

	v.assign(m + 1, 0);

	res.assign(m + 2, {"", ""});

	for (int i = 0; i < m; i++) {
		cin >> v[i + 1];
		string a, b;
		cin >> a >> b;
		res[i + 1] = {a, b};
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j] != res[i].first[j]) {
				adj[0].push_back(i);
				break;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) continue;
			for (int k = 0; k < n; k++) {
				if (res[i].second[k] != res[j].first[k]) {
					adj[i].push_back(j);
					break;
				}
			}
		}
	}


	for (int i = 0; i <= m; i++) {
		cout << i << " -> ";
		pVec(adj[i]);
	}

	// dfs(0, 0, s, -1);
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