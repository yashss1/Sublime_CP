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

	int an = v[0];
	for (int i = 1; i < n; i++) {
		an = an & v[i];
	}

	if (an != 0) {
		cout << "1\n";
		return;
	}

	// cout << an << "\n";
	int ans = 0;
	int curr = pow(2ll, 30ll) - 1ll;
	for (int i = 0; i < n; i++) {
		curr &= v[i];
		if (curr == 0) {
			ans++;
			curr = pow(2ll, 30ll) - 1ll;
		}
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