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
Find all pairs with absolute difference of exact k

INPUT:
2
7
3 6 15 9 6 15 3
6
6
10 15 23 14 2 15
13

OUTPUT:
4
3
*/

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int k;
	cin >> k;

	map<int, int> mp;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int want = k + v[i];
		int want2 = v[i] - k;
		// cout << v[i] << " " << want << " " << want2 << '\n';
		ans += mp[want] + mp[want2];
		if (want == want2) {
			ans -= mp[want];
		}
		mp[v[i]]++;
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