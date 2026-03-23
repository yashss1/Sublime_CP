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

void yash()
{
	int n, k, p, m;
	cin >> n >> k >> p >> m;

	vector<int> v(n);
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		q.push({i, v[i]});
	}

	for (int i = 0; i < n; i++) {
		q.push({i, v[i]});
	}

	int winCost = v[p - 1];

	int curr = 0;
	int ans = 0;

	while (curr <= m) {
		vector<pair<int, int>> temp, temp2;
		queue<pair<int, int>> newQ;

		int smallest = 1e5, smallest_idx = -1;
		for (int i = 0; i < k; i++) {
			auto x = q.front();
			if (smallest > x.second) {
				smallest = min(smallest, (int)x.second);
				smallest_idx = x.first;
			}

			q.pop();
			temp.push_back(x);
		}
		for (int i = k; i < n; i++) {
			auto x = q.front();
			q.pop();
			temp2.push_back(x);
		}

		bool flag = false;
		for (auto &x : temp) {
			if (x.first == p - 1) {
				flag = true;
				break;
			}
		}

		if (flag) { // present ahe
			if (curr + winCost > m) break;
			curr += winCost;
			ans++;
			for (auto &x : temp) {
				if (x.first != p - 1)
					newQ.push(x);
			}
			for (auto &x : temp2) {
				newQ.push(x);
			}

			newQ.push({p - 1, winCost});
		}
		else {

			if (curr + smallest > m) break;
			curr += smallest;
			for (auto &x : temp) {
				if (x.first != smallest_idx)
					newQ.push(x);
			}
			for (auto &x : temp2) {
				newQ.push(x);
			}

			newQ.push({smallest_idx, smallest});
		}

		q = newQ;
	}

	cout << ans << "\n";
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