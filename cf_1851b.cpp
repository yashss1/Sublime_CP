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
	vector<int> v(n), o, e;
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		temp[i] = (v[i] % 2);
		if (v[i] % 2 == 0) {
			e.push_back(v[i]);
		}
		else {
			o.push_back(v[i]);
		}
	}

	sort(e.begin(), e.end());
	sort(o.begin(), o.end());

	int p = 0, q = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (temp[i] == 0) {
			ans[i] = e[p];
			p++;
		}
		else {
			ans[i] = o[q];
			q++;
		}
	}
	vector<int> ans1 = ans;
	sort(ans1.begin(), ans1.end());

	if (ans == ans1) {
		cout << "YES\n"; return;
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