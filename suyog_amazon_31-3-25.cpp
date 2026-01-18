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

vector<vector<int>> solve(int deviceCapacity, vector<vector<int>> foreground, vector<vector<int>> background) {
	int n = foreground.size(), m = background.size(), mx = 0;

	map<int, vector<pair<int, int>>> mp;
	vector<vector<int>> temp;
	for (int i = 0; i < m; i++) {
		temp.push_back({background[i][1], background[i][0]});
	}
	sort(temp.begin(), temp.end());

	for (int i = 0; i < n; i++) {
		int l = 0, r = background.size() - 1, idx = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (foreground[i][1] + temp[mid][0] <= deviceCapacity) {
				l = mid + 1;
				idx = mid;
			} else {
				r = mid - 1;
			}
		}
		if (idx != -1) {
			mx = max(mx, foreground[i][1] + temp[idx][0]);
			mp[foreground[i][1] + temp[idx][0]].push_back({foreground[i][0], temp[idx][1]});
		}
	}

	vector<vector<int>> ans;
	for (auto it : mp[mx]) {
		ans.push_back({it.first, it.second});
	}

	if (ans.size() == 0) {
		ans.push_back({ -1, -1});
	}

	return ans;
}

void yash()
{
	int n, m, deviceCapacity;
	cin >> n >> m >> deviceCapacity;
	vector<vector<int>> foreground, background;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		foreground.push_back({a, b});
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		background.push_back({a, b});
	}
	vector<vector<int>> ans = solve(deviceCapacity, foreground, background);
	for (auto it : ans) {
		cout << it[0] << " " << it[1] << '\n';
	}

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