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
	int a, b, c;
	cin >> a >> b >> c;

	int initA = a;

	if (a + 1 != c) {
		cout << "-1\n";
		return;
	}
	// cout << "0\n";

	int k = 0;
	int singles = c;
	while (a >= pow(2, k)) {
		a -= pow(2, k);
		k++;
	}

	int rem = pow(2, k);

	if (a != 0) {
		rem -= a;
	}
	if (a != 0 || b != 0) {
		k++;
	}

	b = max(0ll, b - rem);
	if (b > 0 && singles != 0) {
		k += (b / singles) + (b % singles == 0 ? 0 : 1);
	}

	// cout << rem << " " << a << " " << k << '\n';
	cout << k << '\n';
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