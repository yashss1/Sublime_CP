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
2
20 3 10
1 2 4 5 10 11 13 15 17 19
45 7 19
1 2 4 5 6 8 9 10 12 13 15 16 17 18 19 20 21 23 24
*/

int dp[51][101][501];
int go(int idx, int remBags, int remW, int n, int* V) {
	if (remBags < 0 || remW < 0) return 0;
	if (idx == n) {
		if (remBags == 0 && remW == 0) {
			return 1;
		}
		return 0;
	}

	int &ans = dp[idx][remBags][remW];
	if (ans != -1) {
		return ans;
	}

	int c1 = go(idx + 1, remBags - 1, remW - V[idx], n, V);
	int c2 = go(idx + 1, remBags, remW, n, V);

	return ans = c1 + c2;
}

void yash()
{
	int target, nbags, n;
	cin >> target >> nbags >> n;
	int V[100];
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < nbags + 1; j++) {
			for (int k = 0; k < target + 1; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	int ans = go(0, nbags, target, n, V);
	return ans;
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