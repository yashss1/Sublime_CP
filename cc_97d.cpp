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

vector<int> pows;
void solve() {
	int x = 1;
	for (int i = 0; i <= 61; i++) {
		pows.push_back(x);
		x *= 2;
	}
}

void yash()
{
	int n, q;
	cin >> n >> q;

	// pVec(pows);
	// cout << pows.size() - 1 << '\n';



	// find pattern
	// int x;
	// cin >> x;
	// vector<int> v(n);
	// for (int i = 1; i <= n; i++) {
	// 	v[i - 1] = (x ^ i);
	// }
	// pVec(v);
	// for (int i = 1; i <= 50; i++) {
	// cout << bitset<6>(i).to_string() << "\n";
	// }

	int multiples = log2(n); // next power of 2;
	multiples++;
	int poww = pow(2ll, multiples);
	// cout << poww << "||\n";

	while (q--) {
		int l, r;
		cin >> l >> r;
		if (n == 1) {
			cout << (r - l + 1) << '\n';
			continue;
		}

		int ans = 0;
		// range -> {l, r} && {n, infinty}
		l = max(l, n);
		// range -> {n, r};

		// for (int i = l; i <= r; i++) {
		// 	int x = i % poww;
		// 	if (x == (poww - 1) || x == 0) {
		// 		cout << i << '\n';
		// 		ans++;
		// 	}
		// }

		int t1 = (r / poww);
		int t2 = (l / poww);
		int z = t1 - t2;
		int zz = z;
		z += (l % poww == 0);
		if ((l % poww) == poww - 1) {
			zz++;
		}
		// cout << z << " " << zz << '\n';
		ans += zz + z;
		cout << ans << '\n';
	}
	// cout << "||||\n";
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	test
	yash();
	return 0;
}