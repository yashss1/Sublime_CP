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
	vector<pair<int, int>> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}

	sort(all(a));
	sort(all(b));

	vector<pair<int, int>> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i].first = a[i].second;
		ans[i].second = b[i].first;
	}

	sort(all(ans));

	for (int i = 0; i < n; i++) {
		cout << ans[i].second << ' ';
	}
	cout << "\n";


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