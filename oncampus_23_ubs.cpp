// YashS
#include <bits/stdc++.h>
using namespace std;
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pVec(v)           \
    for (auto e : v)      \
        cout << e << " "; \
    cout << "\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
Scheduling, assign servers
INPUT:
3 5
2 4 1 8 9
7 9 2 4 5

OUTPUT:
1 2 1 3 2
*/
vector<int> getServerIndex(int n, vector<int> a, vector<int> b) {
	int m = a.size();

	vector<pair<int, int>> v;
	for (int i = 0; i < m; i++) {
		v.push_back({ a[i], b[i] });
	}
	sort(v.begin(), v.end());

	vector<int> loadOnServer(n);
	for (int i = 0; i < n; i++) {
		loadOnServer[i] = 0;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;

	set<int> availableServers;
	for (int i = 1; i <= n; i++) {
		availableServers.insert(i);
	}

	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int endTime = v[i].first + v[i].second;

		while (!busyServers.empty() && busyServers.top().first <= v[i].first) {
			pair<int, int> releasedServer = busyServers.top();
			busyServers.pop();
			availableServers.insert(releasedServer.second);
		}

		if (availableServers.size() == 0) {
			ans.push_back(-1);
			continue;
		}

		int temp = *(availableServers.begin());
		ans.push_back(temp);

		availableServers.erase(temp);
		busyServers.push({ endTime, temp });
	}

	return ans;
}

/*
Print smallest lexicographical string with subtring in S

INPUT:
hgferyjkllkop
5
coffee coding happy hello hop

OUTPUT:
hello
*/

string getValidWord(string s, vector<string> v) {
	int n = v.size();
	int m = s.size();

	vector<string> ans;
	for (int i = 0; i < n; i++) {
		int p = 0, q = 0;

		while (p < m && q < v[i].size()) {
			if (s[p] == v[i][q]) {
				p++, q++;
			} else {
				p++;
			}
		}
		if (q == v[i].size()) {
			ans.push_back(v[i]);
		}
	}

	if (ans.size() == 0) {
		return "-1";
	}
	return ans[0];
}

void yash() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	vector<int> ans = getServerIndex(n, a, b);
	pVec(ans);

	// string s;
	// cin >> s;
	// int n;
	// cin >> n;
	// vector<string> v(n);
	// for (int i = 0; i < n; i++) {
	// 	cin >> v[i];
	// }

	// string ans = getValidWord(s, v);
	// cout << ans << '\n';
}

signed main() {
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}