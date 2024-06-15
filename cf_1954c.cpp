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
	string a, b;
	cin >> a >> b;
	int n = a.size();

	int diff = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			diff = i;
			break;
		}
	}

	if (diff == -1) {
		cout << a << '\n' << b << '\n';
		return;
	}

	if (a[diff] < b[diff]) swap(a[diff], b[diff]);

	for (int i = diff + 1; i < n; i++) {
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
	}

	cout << a << "\n" << b << '\n';
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