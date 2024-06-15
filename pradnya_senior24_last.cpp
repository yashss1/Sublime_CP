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

int k, m;
int n;
string l, r;
int dp[2][19][16][51];

int go(int idx, int upper, int modN, int xoor) {
	if (idx == r.size()) {
		return modN == xoor;
	}

	int &ans = dp[upper][idx][xoor][modN];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = 0; i < 10; i++) {
		if (upper && (i > (r[idx] - '0'))) continue;

		int modNew = (modN * 10) + (i);
		modNew %= m;

		ans += go(idx + 1, upper && (i == (r[idx] - '0')), modNew, (xoor ^ i));
	}

	return ans;
}

int solve(int L, int R) {
	memset(dp, -1, sizeof(dp));
	r = to_string(R);

	// This gives total numbers from l to r which satisfies this condition
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (i > (r[0] - '0')) continue;
		int modNew = i;
		modNew %= m;
		ans += go(1, i == (r[0] - '0'), modNew, i);
	}

	return ans;
}

void yash()
{
	cin >> k >> m;

	int l = 0, r = 1e18;
	int ans = 1e18;
	while (l <= r) {
		int mid = (l + r) / 2;
		int temp = solve(0, mid);
		if (temp >= k) {
			ans = mid;
			r = mid -  1;
		}
		else {
			l = mid + 1;
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
	// test
	yash();
	return 0;
}