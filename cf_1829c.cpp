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

	set<int> mp[3];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		string s; cin >> s;
		if (s[0] == '1' && s[1] == '1') {
			mp[0].insert(x);
		} else if (s[0] == '1') {
			mp[1].insert(x);
		}
		else if (s[1] == '1') {
			mp[2].insert(x);
		}
	}

	int ans = INT_MAX;
	if (mp[0].size() != 0) {
		ans = (*mp[0].begin());
	}

	if (mp[1].size() != 0 && mp[2].size() != 0) {
		ans = min(ans, (*mp[1].begin()) + (*mp[2].begin()));
	}

	if (ans == INT_MAX) {
		cout << "-1\n";
		return;
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