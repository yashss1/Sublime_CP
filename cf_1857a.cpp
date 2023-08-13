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

// E
void yash()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	// for (auto it : v) {
	// 	cout << it.first << " " << it.second << "\n";
	// }

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(v[0].first - v[i].first) + 1;
	}
	int prev = ans;

	map<int, int> mp;
	mp[v[0].second] = prev;
	for (int i = 1; i < n; i++) {
		int back = i;
		int front = (n - i);
		// cout << back << " " << front << '\n';
		int diff = v[i].first - v[i - 1].first;
		int curr = prev + (back * diff) - (front * diff);

		mp[v[i].second] = curr;
		prev = curr;
		// cout << v[i].second << " " << curr << '\n';
	}

	vector<int> res(n);
	for (auto it : mp) {
		res[it.first] = it.second;
	}

	pVec(res);
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