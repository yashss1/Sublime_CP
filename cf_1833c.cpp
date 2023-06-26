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
	vector<int> v(n);
	int e = INT_MAX, o = INT_MAX, oo = 0;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;

		if (v[i] % 2 == 0) {
			e = min(e, v[i]);
		}
		else {
			oo = 1;
			o = min(o, v[i]);
		}
	}

	// cout << o << '\n';

	int even = 1, odd = 1;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) {
			continue;
		}
		if (o < v[i] && oo == 1) {
			continue;
		}
		even = 0;
	}

	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 1) {
			continue;
		}
		if (o < v[i] && oo == 1) {
			continue;

		}
		odd = 0;
	}

	// cout << even << " " << odd << '\n';


	if (even == 1 || odd == 1) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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