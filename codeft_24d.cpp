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

vector<int> printDivisors(int n)
{
	vector<int> divisors;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (n / i == i) {
				divisors.pb(i);
			}

			else {
				divisors.pb(i);
				divisors.pb(n / i);
			}
		}
	}
	return divisors;
}

void yash()
{
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		vector<int> temp = printDivisors(v[i]);
		for (auto it : temp) {
			mp[it]++;
		}
	}

	map<int, vector<int>> hehe, hehe2;
	for (int i = 1; i <= 1e6; i++) {
		if (mp[i] > 0) {
			hehe[mp[i]].push_back(i);
		}
	}
	for (auto it : hehe) {
		for (auto it1 : it.second) {
			hehe2[it1].push_back(it.first);
		}
	}

	// for (auto it : hehe2) {
	// 	cout << it.first << " -> ";
	// 	pVec(it.second);
	// }

	while (q--) {
		int k, l, r;
		cin >> k >> l >> r;
		if (hehe[k].size() == 0) {
			cout << "-1 ";
			continue;
		}

		// find k in hehe from hehe[l] to hehe[r]
		int L = 0, R = hehe[k].size() - 1, ans = -1;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (hehe[k][mid] <= r) {
				ans = mid;
				L = mid + 1;
			}
			else {
				R = mid - 1;
			}
		}

		if (ans == -1) {
			cout << "-1 ";
			continue;
		}
		if (hehe[k][ans] < l) {
			cout << "-1 ";
			continue;
		}

		cout << hehe[k][ans] << ' ';

	}
	cout << '\n';
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