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
Similar to LRU. but access does not increase priority
INPUT:
6
1 2 1 3 1 2
2

OUTPUT:
5
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

	queue<int> q;
	map<int, int> mp;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (q.size() == k && mp[v[i]] == 0) {
			int t = q.front();
			mp[t]--;
			q.pop();
		}

		if (mp[v[i]] == 0) {
			ans++;
			q.push(v[i]);
		}

		mp[v[i]] = 1;
	}

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