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
	vector<int> a(n), b(n);

	int a1 = 0, b1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a1 += a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b1 += b[i];
	}


	if ((a1 + b1) % 2 == 0) {
		cout << "Tie\n"; return;
	}

	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			if (a[i] != b[i]) {
				flag = 1;
			}
		}
		else {
			if (a[i] != b[i]) {
				flag = 0;
			}
		}
	}

	if (flag) {
		cout << "Mai\n";
		return;
	} cout << "Ajisai\n";
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