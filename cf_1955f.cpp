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
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (d % 2) d--;
	int x = a / 2 + b / 2 + c / 2 + d / 2;

	if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
		cout << x << endl;
		return;
	}

	int numOdd = 0;

	if (a % 2) numOdd++;
	if (b % 2) numOdd++;
	if (c % 2) numOdd++;

	if (numOdd == 3 || numOdd == 0) {
		cout << x + 1 << "\n";
		return;
	}
	cout << x << '\n';
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