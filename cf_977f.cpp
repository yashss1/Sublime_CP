//YashS
// TLE solution but N is small so most probably WA or RTE
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

int n;
vector<int> v(N);

int dp[N];

int go(int idx) {
	if (idx == n) {
		return 0;
	}

	int &ans = dp[idx];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = idx + 1; i < n; i++) {
		if (v[i] == v[idx] + 1) {
			ans = max(ans, 1 + go(i));
		}
	}

	return ans;
}

void trace(int idx) {
	if (idx == n) {
		return;
	}

	int ans = dp[idx];

	for (int i = idx + 1; i < n; i++) {
		if (v[i] == v[idx] + 1) {
			if (go(i) + 1 == ans) {
				cout << i + 1 << ' ';
				trace(i);
			}
		}
	}
	// assert(false);
}



void yash()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, 1 + go(i));
	}

	cout << ans << '\n';

	// for (int i = 0; i <= n; i++) {
	// 	cout << dp[i] << " ";
	// } cout << '\n';

	for (int i = 0; i < n; i++) {
		if (go(i) + 1 == ans) {
			cout << i + 1 << " ";
			trace(i);
			break;
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
	// test
	yash();
	return 0;
}