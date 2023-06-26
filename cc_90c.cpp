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


vector<int> v;

void go(int n, int k) {
	if (n == 0) {
		return;
	}

	v.push_back(n);
	if (n % 2 == 0) {
		go(n / 2, k + 1);
	}
}


int solve(int n) {
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] > n) {
			continue;
		}

		// cout << t << '\n';
		if (n >= v[i]) {
			n -= v[i];
		}
	}
	if (n == 0) {
		return 1;
	}
	return 0;
}

void yash()
{
	int m, n;
	cin >> m >> n;
	v.clear();
	if (n > m) {
		cout << "NO\n";
		return;
	}

	if (m == n) {
		cout << "YES\n";
		return;
	}


	go(m, 0);
	sort(all(v));
	// for (auto it : mp) {
	// 	cout << it.first << " " << it.second << '\n';
	// }

	// pVec(v);
	int ans = solve(n);
	if (ans == 1) {
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