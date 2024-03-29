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
const int N = 1e5 + 7;

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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> dp(515, INT_MAX); //tells i is XOR of any subsequence till current idx
	set<int> st;
	st.insert(0);

	for (int i = 0; i < n; i++) {
		dp[v[i]] = min(dp[v[i]], v[i]);
		for (int j = 0; j <= 513; j++) {
			if (dp[j] != INT_MAX && dp[j] < v[i]) {
				dp[j ^ v[i]] = min(dp[j ^ v[i]], v[i]);
			}
		}
	}

	for (int i = 0; i <= 514; i++) {
		if (dp[i] != INT_MAX) {
			st.insert(i);
		}
	}
	cout << st.size() << '\n';
	pVec(st);
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