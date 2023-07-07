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

/*
1000
0010
0100
1100
0001

0001
1101
1001
1011
0011

0011
1011
1001
1101
0001

*/

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n), hsh(n, 0), hsh2(n, 0);
	set<int> st;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int xr = 0;
	for (int i = n - 1; i >= 0; i--) {
		xr = xr ^ v[i];
		hsh[i] = xr;
		st.insert(hsh[i]);
	}

	int xr1 = 0, mx = 0;
	for (int i = n - 1; i >= 0; i--) {
		xr1 = xr1 ^ hsh[i];
		hsh2[i] = xr1;
		mx = max(mx, hsh2[i]);
	}

	pVec(hsh);
	pVec(hsh2);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int t1 = hsh[i], t2 = hsh2[j];
			cout << (t1 ^ t2) << " ";
		}
	}
	cout << '\n';
	// cout << mx << '\n';
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