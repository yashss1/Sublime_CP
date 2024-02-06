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
vector<int> v;
vector<vector<int>> dp;

int go(int idx, int done) {
	// cout << idx << " " << done << '\n';
	if (idx >= n || done >= n - 1) {
		return 0;
	}

	int k = 0;

	int &ans = dp[idx][done + 1];
	if (ans != -1) {
		return ans;
	}

	ans = INT_MAX;
	int udhar = idx;
	for (int i = idx; i < n; i++) {
		// ans = min(ans, 1 + go(idx + 1, i + v[idx]));
		k++;
		int fl = 0;
		// if (idx==0){
		//     cout<<i<<" "<<v[i]<<" "<<udhar<<endl;
		// }
		if (v[i] >= k)
		{
			ans = min(ans, 1 + go(i + 1, max(done, i)));
			if (udhar > i) {
				ans = min(ans, 2 + go(udhar + 1, max({i, done, udhar})));
			}
		}
		if (fl == 0)
		{
			udhar = max(udhar, i + v[i] - 1);
		}
	}

	// if (done < idx) {
	ans = min(ans, 1 + go(idx + 1, max(idx + v[idx] - 1, done)));
	// }
	if (done >= idx) {
		ans = min(ans, go(idx + 1, done));
	}
	return ans;
}


void yash()
{
	cin >> n;
	v.assign(n, 0);
	dp.assign(n + 5, vector<int>(2 * n, -1));
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = go(0, -1);
	cout << ans << "\n";
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