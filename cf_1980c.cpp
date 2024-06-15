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
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int m;
	cin >> m;
	vector<int> c(m);
	map<int, int> mp;
	for (int i = 0; i < m; i++) {
		cin >> c[i];
		mp[c[i]]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (mp[b[i]] > 0) {
				mp[b[i]]--;
				continue;
			}
			ans = 1;
			break;
		}
	}

	if (ans) {
		cout << "NO\n"; return;
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == c[m - 1]) {
			cout << "YES\n";
			return;
		}
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