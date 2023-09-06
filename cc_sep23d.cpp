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


void yash()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<int> pref(n), suff(n);

	pref[0] = a[0];
	int res = a[0];

	for (int i = 1; i < n; i++) {
		pref[i] = gcd(pref[i - 1], a[i]);
		res = gcd(res, a[i]);
	}

	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suff[i] = gcd(suff[i + 1], a[i]);
	}

	// pVec(pref);
	// pVec(suff);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int gcdd = 0;

		if (i > 0 && i < n - 1) {
			gcdd = gcd(pref[i - 1], suff[i + 1]);
		}
		else if (i > 0) {
			gcdd = pref[i - 1];
		}
		else if (i < n - 1) {
			gcdd = suff[i + 1];
		}

		gcdd = gcd(gcdd, b[i]);

		ans = max(ans, gcdd);
	}

	cout << max(res, ans) << '\n';
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