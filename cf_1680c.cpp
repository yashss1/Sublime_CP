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

void yash()
{
	string s;
	cin >> s;
	int n = s.size();

	vector<int> pref0(n + 1, 0), pref1(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pref0[i + 1] += pref0[i];
		pref1[i + 1] += pref1[i];
		if (s[i] == '0') {
			pref0[i + 1]++;
		} else {
			pref1[i + 1]++;
		}
	}

	// pVec(pref0);
	// pVec(pref1);


	int one = 0, ans = pref0[n];
	for (int i = 0; i <= n; i++) {
		// i + 1 to n

		int l = i + 1, r = n;
		int zeroIn = pref0[n] - pref0[i], oneOut = one;
		// cout << i << " -> " << zeroIn << " " << oneOut << " | \n";
		while (l <= r) {
			int mid = (l + r) / 2;
			oneOut = pref1[n] - pref1[mid] + one;
			zeroIn = pref0[mid] - pref0[i];

			// cout << mid << " " << zeroIn << " " << oneOut << '\n';

			if (oneOut < zeroIn) {
				r = mid - 1;
			}
			else {
				ans = min(ans, max(oneOut, zeroIn));
				l = mid + 1;
			}
		}

		if (s[i] == '1') {
			one++;
		}

		// cout << "HERE : " << zeroIn << " " << oneOut << '\n';
		ans = min(ans, max(oneOut, zeroIn));
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