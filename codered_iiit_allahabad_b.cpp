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
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> fibon(N), pref(N);
void fib() {
	fibon[1] = 1; fibon[0] = 1;
	fibon[2] = 2;
	pref[1] = 0, pref[2] = 3, pref[0] = 1;
	for (int i = 3; i < N; i++) {
		fibon[i] = fibon[i - 1] + fibon[i - 2];
		pref[i] += pref[i - 1] + fibon[i];
	}
}

void yash()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	// for (int i = 0; i < 10; i++) {
	// 	cout << i << " -> " << fibon[i] << "\n";
	// }
	// for (int i = 0; i < 10; i++) {
	// 	cout << i << " -> " << pref[i] << "\n";
	// }

	int prev = 0, ans = 1;
	for (int i = 0; i < m; i++) {
		if (v[i] == 1) {
			prev = 1;
			continue;
		}
		int diff = max(0ll, v[i] - prev - 2);
		cout << i << " " << diff << ' ' << pref[diff + 1] << "\n";
		ans *= (max(1ll, pref[diff + 1]));
		prev = v[i];
	}
	if (v[m - 1] != n) {
		ans *= (pow(2, (n - v[m - 1])));
	}
	cout << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fib();
	test
	yash();
	return 0;
}