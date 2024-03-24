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

string s;
int n, k;

int go(int idx, int edge, int mask, int taken) {
	if (idx == n) {
		for (int i = 0; i < 10; i++) {
			if (taken & (1 << i)) {
				return 0;
			}
		}
		return 1;
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (mask & (1 << i)) {
			if ((taken & (1 << i))) {
				taken ^= (1 << i);
			}
			ans |= go(idx + 1, edge, mask, taken);
		}
	}
	return ans;
}

void yash()
{
	cin >> s >> k;
	n = s.size();

	int ans = 0;
	for (int i = 0; i < pow(2, k) - 1ll; i++) {
		ans = go(0, 0, 0, i);
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