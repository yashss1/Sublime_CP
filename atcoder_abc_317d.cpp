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
vector<vector<int>> v;
vector<vector<int>> vv;
int dp[200][200000];
int want;

int go(int idx, int extra) {
	if (idx == n) {
		if (extra >= want) {
			return 0;
		}
		return 1e9;
	}

	int &ans = dp[idx][extra];
	if (ans != -1) {
		return ans;
	}

	int x = vv[idx][0], y = vv[idx][1], z = vv[idx][2];
	int needChange = ((y - x + 1) / 2);

	int c1 = needChange + go(idx + 1, extra + z);
	int c2 = go(idx + 1, extra);

	return ans = min({c1, c2});
}

void yash()
{
	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({x, y, z});
		if (x > y) {
			a += z;
		}
		else {
			b += z;
			vv.push_back({x, y, z});
		}
	}
	if (a > b) {
		cout << "0\n"; return;
	}

	n = vv.size();
	memset(dp, -1, sizeof(dp));
	want = (a + b + 1) / 2;
	int ans = go(0, a);
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