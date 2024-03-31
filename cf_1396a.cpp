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

int gcd(int a, int b)
{
	while (a > 0 && b > 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	if (a == 0) {
		return b;
	}
	return a;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			cout << "1 1\n";
			if (i == 1)
				cout << 1 * v[0] << '\n';
			else
				cout << -1 * v[0] << '\n';
		}
		return;
	}

	cout << "1 1\n";
	cout << -1 * v[0] << '\n';

	int lc = 1;
	for (int i = 1; i < n; i++) {
		lc = lcm(lc, v[i]);
	}

	cout << "1 " << n << '\n';
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << "0 ";
		} else
			cout << -1 * n*v[i] << " ";
	} cout << '\n';

	cout << "2 " << n << "\n";
	for (int i = 1; i < n; i++) {
		cout << (n - 1)*v[i] << ' ';
	} cout << '\n';
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