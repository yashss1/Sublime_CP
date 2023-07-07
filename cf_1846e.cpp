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
int N = 1e6 + 1e5;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

set<int> st;
void solve(int n) {
	for (int i = 2; i <= n; i++) {
		int init = pow(i, 0) + pow(i, 1) + pow(i, 2);
		st.insert(init);
		int x = 3;
		// cout << init << "\n";

		while (init + pow(i, x) <= (1e18)) {
			init += pow(i, x);
			x++;
			st.insert(init);
		}
	}
}

void yash()
{
	int n;
	cin >> n;
	// pVec(st);
	if (st.find(n) != st.end()) {
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
	solve(N);
	test
	yash();
	return 0;
}