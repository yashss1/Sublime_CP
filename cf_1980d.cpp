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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> gg(n + 1, 0);
	vector<int> pref(n + 2, 0);
	vector<int> suff(n + 2, 0);

	for (int i = 1; i < n; i++) {
		gg[i] = gcd(v[i - 1], v[i]);
	}

	int flag = 1;
	pref[0] = 1, pref[1] = 1;
	for (int i = 1; i < n; i++) {
		if (gg[i - 1] <= gg[i] && flag == 1) {
			pref[i + 1] = 1;
		} else {
			flag = 0;
			pref[i + 1] = 0;
		}
	}

	flag = 1;
	suff[n] = 1, suff[n + 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (gg[i + 1] >= gg[i] && flag == 1) {
			suff[i + 1] = 1;
		} else {
			flag = 0;
			suff[i + 1] = 0;
		}
	}

	pVec(v);
	pVec(gg);
	pVec(pref);
	pVec(suff);

	int res = 0;
	for (int i = 2; i <= n - 1; i++) {
		cout << i << '\n';
		if (pref[i - 2] == 1 && suff[i + 2]) {
			res = 1;
			// cout << i << '\n';
			break;
		}
	}
	if (res) {
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