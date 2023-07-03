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

int n;
vector<int> v(N);
int solve(int k) {
	int ans = 0, flag = 0;
	if (ans >= k) flag = 1;
	for (int i = 0; i < n; i++) {
		if (ans + v[i] < k && flag == 1) {
			ans = k;
		}
		else {
			ans += v[i];
		}
		if (ans >= k) {
			flag = 1;
		}
	}

	return ans;
}

void yash()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> hsh(n);
	int curr = 0;
	for (int i = 0; i < n; i++) {
		curr += v[i];
		hsh[i] = curr;
	}
	set<int> st;
	for (auto it : hsh) {
		st.insert(it);
	}

	int ans = 0, mx = 0;
	for (auto it : st) {
		// cout << it << " " << solve(it) << '\n';
		int t = solve(it);
		if (mx < t) {
			mx = t;
			ans = it;
		}
	}
	cout << ans << '\n';
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