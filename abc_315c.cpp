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
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	map<int, vector<int>> mp;
	map<int, int> mp2;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({b, a});
		mp[a].push_back(b);
		mp2[a] = max(mp2[a], b);
	}

	int ans = 0;
	for (auto it : mp) {
		vector<int> temp = it.second;
		if (temp.size() < 2) continue;
		sort(temp.begin(), temp.end(), greater<int>());
		ans = max(ans, (temp[0] + temp[1] / 2));
	}

	vector<int> temp;
	for (auto it : mp2) {
		temp.push_back(it.second);
	}
	sort(temp.begin(), temp.end(), greater<int>());
	if (temp.size() >= 2)
		ans = max(ans, (temp[0] + temp[1]));

	cout << ans << '\n';
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