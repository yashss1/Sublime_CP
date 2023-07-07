//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define ll                long long
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

ll fact[3000007] = {0};
void facto() {
	fact[0] = 1; fact[1] = 1; for (int i = 2; i < 300000; i++)fact[i] = (fact[i - 1] * i) % MOD;
}
int fpow(int x, int y, int p = MOD) {
	x = x % p; int sum = 1; while (y) {
		if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
	} return sum;
}

ll ncr(ll n, ll r) {
	if (r > n)return 0;
	ll res = 1; res = fact[n]; res = (res * (fpow(fact[r], MOD - 2))) % MOD; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}

void yash()
{
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> hsh(n - 2, 0), temp;
	for (int i = 0; i < n; i++) {
		int x = n - i - 1;
		if (x > 1) {
			x = (x * (x - 1) / 2);
			temp.push_back(x);
		}
	}
	int x = 0;
	for (int i = 0; i < temp.size(); i++) {
		x += temp[i];
		hsh[i] = x;
	}

	// pVec(v);
	// pVec(hsh);

	while (q--) {
		int k;
		cin >> k;
		int l = 0, r = (n - 3), idx = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (hsh[mid] <= k) {
				idx = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		if (hsh[idx] < k) {
			idx++;
		}
		cout << v[idx] << '\n';
	}
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	facto();
	test
	yash();
	return 0;
}