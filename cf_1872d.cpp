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
	int n, a, b;
	cin >> n >> a >> b;

	int temp = (lcm(a, b));
	// cout << temp << "\n";
	int p = (n / a), q = (n / b), r = (n / (temp));
	p -= r;
	q -= r;

	// cout << p << " " << q << '\n';

	p = n - p;

	int t1 = (n * (n + 1) / 2) - (p * (p + 1) / 2);
	int t2 = (q * (q + 1) / 2);

	cout << t1 - t2 << "\n";
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