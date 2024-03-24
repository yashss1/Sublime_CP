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

/*
https://leetcode.com/discuss/interview-question/4719534/uber-OA/
*/

int prime[N + 1] = {0};
void seive(int n) {
	prime[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = 1;
			}
		}
	}
}

void yash()
{
	seive(N - 2);
	int n;
	cin >> n;
	vector<int> pref(N, 0);

	for (int i = 1; i < 100; i++) {
		pref[i] = (prime[i] == 0 ? i : 0) +  pref[i - 1];
	}

	// for (int i = 0; i <= 10; i++) {
	//     cout << i << " -> " << pref[i] << "\n";
	// }

	int ans = 1;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;

		int res = pref[r] - pref[l - 1];
		ans *= res;
		ans %= MOD;
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