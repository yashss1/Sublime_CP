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

int x;
bool go(int a, int b) {
	if (a < b) swap(a, b);
	// (a, b) -> ((a`, b) -> go both sides for this), ((a, b`) -> no need to go right of this)

	if (a == x || b == x || abs(b - a) == x) {
		return true;
	}
	if (a == 0 || b == 0) {
		return false;
	}

	// reduce a till b
	int times = a - ((a / b) * b);

	// what if x >= b && x <= a ???
	// reduce till x only
	if (x > b && x < a) {
		if ((a - x) % b == 0) {
			return true;
		}
	}

	return go(times, b);
}

void yash()
{
	int a, b;
	cin >> a >> b >> x;
	if (go(a, b)) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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