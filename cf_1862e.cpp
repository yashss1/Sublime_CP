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
	int n, m, d;
	cin >> n >> m >> d;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}


	int sum = 0;

	priority_queue<pair<int, int>> pq;
	priority_queue<int> pq2;

	int ans = 0;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (v[i].first < 0) continue;
		pq.push({ -v[i].first, i});
		pq2.push(i);
		sum += v[i].first;
		mp[i] = 1;

		while (pq.size() > m) {
			pair<int, int> temp = pq.top();
			sum += temp.first;
			int idx = temp.second;
			if (pq2.top() == idx) {
				mp[idx] = 0;
			}
			pq.pop();
		}
		while (mp[pq2.top()] == 0) {
			pq2.pop();
		}

		// cout << i << " -> " << sum << " " << (pq2.top()) << " | ";
		int curr = sum - (d * (pq2.top() + 1));
		// cout << curr << '\n';
		ans = max(ans, curr);
	}
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