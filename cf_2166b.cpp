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
	int a, b, n;
	cin >> a >> b >> n;
	if (a == b) {
		cout << "1\n"; return;
	}

	int l = 0, r = n;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		double temp = ((double)a / (double)(n - mid));
		// cout << mid << " " << temp << '\n';

		if (temp >= b) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}

	if (ans != 0) {
		cout << "2\n"; return;
	}
	cout  << "1\n";
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