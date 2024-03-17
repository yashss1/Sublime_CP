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
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int flag = 0;
	for (int i = 0; i < n - 2; ++i) {
		if (v[i] < 0)
			flag = 1;
		v[i + 1] -= (2 * v[i]);
		v[i + 2] -= v[i];
		v[i] = 0;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] == 0)
			cnt++;
	}

	if (cnt == n && flag == 0)
		cout << "YES\n";
	else
		cout << "NO\n";

	return;

	int done = v[0];
	v[0] = 0;
	for (int i = 1; i < n - 1; i++) {
		v[i] -= (done * 2);
		v[i + 1] -= done;

		if (v[i] < 0 || v[i + 1] < 0) {
			cout << "NO\n";
			return;
		}
		if (v[i] > 0) {
			done = v[i];
			v[i] = 0;
		}
	}

	// pVec(v);

	for (int i = 0; i < n; i++) {
		if (v[i] != 0) {
			cout << "NO\n"; return;
		}
	}
	cout << "YES\n";

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