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
	int n, m, l, q;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	cin >> l;
	vector<int> c(l);
	for (int i = 0; i < l; i++) {
		cin >> c[i];
	}
	cin >> q;
	vector<int> x(q);
	for (int i = 0; i < q; i++) {
		cin >> x[i];

		map<int, int> mp;
		for (int o = 0; o < n; o++) {
			for (int k = 0; k < m; k++) {
				mp[a[o] + b[k]]++;
			}
		}

		int flag = 0;
		for (int o = 0; o < l; o++) {
			int want = x[i] - c[o];
			if (mp[want]) {
				cout << "Yes\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "No\n";
	}


}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}