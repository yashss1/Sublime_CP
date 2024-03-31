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

int n;
vector<int> adj[N], level, parent;

void dfs(int node, int par, int lvl) {
	level[node] = lvl;
	parent[node] = par;
	for (auto it : adj[node]) {
		if (it != par) {
			dfs(it, node, lvl + 1);
		}
	}
}

int ans = 0;
void proc(vector<int>& a) {
	if (a.empty()) return;
	int n = a.size();
	int last = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == a[0]) {
			last = i;
		} else {
			break;
		}
	}
	--a[last];
	for (int i = 0; i < n; ++i) --a[i];
	++ans;
	while (!a.empty() && a.back() <= 0) {
		a.pop_back();
	}
	proc(a);
}

void yash()
{
	cin >> n;
	level.assign(n + 1, 0);
	parent.assign(n + 1, 0);
	for (int i = 0; i < n + 5; i++) {
		adj[i].clear();
	}

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}

	dfs(1, -1, 0);

	map<int, int> mp; // par, level
	for (int i = 1; i <= n; i++) {
		mp[parent[i]]++;
	}

	vector<int> temp;
	for (auto it : mp) {
		if (it.second > 1)
			temp.push_back(it.second - 1);
	}

	sort(temp.begin(), temp.end(), greater<int>());
	int res = mp.size() - 1;
	ans = mp.size();

	vector<int> temp2;
	for (int i = 0; i < temp.size(); i++) {
		temp[i] -= res;
		res = max(0ll, res - 1);
		if (temp[i] > 0) {
			temp2.push_back(temp[i]);
		}
	}
	sort(temp2.begin(), temp2.end(), greater<int>());
	proc(temp2);

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