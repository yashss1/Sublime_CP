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

/*
3
7
3 3 3 4 4 1 8
5
1 2 3 4 5
4
1 1 1 2
*/

int dp[100001];
int go(int idx, int mx, map<int, int>&mp) {
	if (idx > mx) {
		return 0;
	}

	int &ans = dp[idx];
	if (ans != -1) {
		return ans;
	}

	int c1 = 0, c2 = 0;
	if (mp[idx] != 0) {
		c1 = (mp[idx] * idx) + go(idx + 2, mx, mp);
	}
	c2 = go(idx + 1, mx, mp);

	return ans = max({c1, c2});
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int mx = 0;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
		mx = max(mx, v[i]);
	}

	memset(dp, -1, sizeof(dp));
	int ans = go(1, mx, mp);
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