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
const int N = 1e7 + 7;

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

int spf[N + 1]; //Can go upto N = 1e7
void SPF() {
	spf[1] = 1;
	rep(i, 2, N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
}

void yash()
{
	int a, b;
	cin >> a >> b;
	if (gcd(a, b) > 1) {
		cout << "0\n";
		return;
	}
	if (a % 2 && b % 2) {
		cout << "1\n"; return;
	}

	if (a > b) swap(a, b);
	if (b - a == 1) {
		cout << "-1\n";
		return;
	}

	int temp = spf[b - a];
	int next = ((b / temp) + 1) * temp;

	cout << (next - b) << "\n";

	// for (int i = 0; i < 1000; i++) {
	// 	if (gcd(a + i, b + i) > 1) {
	// 		cout << i << ' ' << a + i << " " << b + i << "\n";
	// 		cout << gcd(a + i, b + i) << '\n';
	// 		return;
	// 	}
	// }
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	SPF();
	test
	yash();
	return 0;
}