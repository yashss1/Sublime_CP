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
const int N = 1e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int spf[N + 1]; //Can go upto N = 1e7
void SPF() {
	spf[1] = 1;
	rep(i, 2, N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
}


void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);

	vector<int> dp(1e6 + 2, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[v[i]]++;
	}
	sort(v.begin(), v.end());

	for (int i = 1e6; i >= 0; i--) {
		if (dp[i] == 0) {
			continue;
		}

		int mx = 0;
		for (int j = 2 * i; j <= 1e6 + 1; j += i) {
			mx = max(mx, dp[j]);
		}
		dp[i] += mx;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[v[i]]);
	}
	cout << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	SPF();
	yash();
	return 0;
}