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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	if (k % 2 == 0) {
		sort(all(s));
		cout << s << '\n';
		return;
	}

	// cout << s << '\n';

	vector<char> a, b;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			a.push_back(s[i]);
		}
		else {
			b.push_back(s[i]);
		}
	}
	sort(all(a)); sort(all(b));

	int p = 0, q = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cout << a[p];
			p++;
		}
		else {
			cout << b[q];
			q++;
		}
	}
	cout << '\n';
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