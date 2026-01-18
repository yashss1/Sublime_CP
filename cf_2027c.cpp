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

map<int, vector<int>> mp;

int go(int node) {
	if (mp[node].size() == 0) {
		return node;
	}

	int ans = node;
	for (auto it : mp[node]) {
		if (it == node) continue;
		ans = max(ans, go(it));
	}

	return ans;
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	mp.clear();

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i] + (i + 1) - 1].push_back(v[i] + (i + 1) - 1 + i);
		// cout << v[i] << " " << (v[i] + (i + 1) - 1) << "\n";
	}

	int ans = go(n);
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