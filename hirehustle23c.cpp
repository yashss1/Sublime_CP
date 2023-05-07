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
int N = 1e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int mod_add(int a, int b, int m) {
	a = a % m; b = b % m;
	return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

void yash()
{
	// for (int tc = 3; tc <= 14; tc++) {
	// 	string infile = "input" + to_string(tc) + ".txt";
	// 	string outfile = "output" + to_string(tc) + ".txt";
	// 	freopen(infile.c_str(), "r", stdin);
	// 	freopen(outfile.c_str(), "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<int> v1(n + 2, 0), v2(n + 2, 0), v3(n + 2, 0), v4(n + 2, 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l > r) {
			assert(false);
		}
		int t = (r - l + 1);
		int t1 = (t * (t + 1) / 2ll);
		int t2 = (t * (t + 1) * (t + 2) / 6ll);
		v1[l] += (1ll);
		v1[r + 1] -= (1ll);
		v2[r + 1] -= (t);
		v3[r + 1] -= (t1);
		v4[r + 1] -= (t2);
	}

	for (int i = 1; i <= n; i++) {
		v1[i] = mod_add(v1[i], v1[i - 1], MOD);
	}

	for (int i = 1; i <= n; i++) {
		v2[i] = mod_add(v2[i], v2[i - 1], MOD);
		v2[i] = mod_add(v2[i], v1[i], MOD);
	}

	for (int i = 1; i <= n; i++) {
		v3[i] = mod_add(v3[i], v3[i - 1], MOD);
		v3[i] = mod_add(v3[i], v2[i], MOD);
	}

	for (int i = 1; i <= n; i++) {
		v4[i] = mod_add(v4[i], v4[i - 1], MOD);
		v4[i] = mod_add(v4[i], v3[i], MOD);
	}

	// pVec(v4);
	for (int i = 1; i <= n; i++) {
		cout << v4[i] << " ";
	}
	cout << '\n';
	// }
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}