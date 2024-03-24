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
	int n;
	cin >> n;
	string s;
	cin >> s;

	// for (int i = 0; i < n - 2; i++) {
	// 	string curr = s.substr(i, 3);
	// 	if (curr[0] == curr[1] && curr[1] == curr[2]) {

	// 	}
	// 	else {
	// 		if (i >= 3 && s[i] == s[i - 3]) {

	// 		}
	// 		else {
	// 			if (i >= 1 && s[i] == s[i - 1]) {

	// 			}
	// 			else {
	// 				ans++;
	// 			}
	// 		}
	// 	}
	// }

	int ans = n - 2;

	for (int i = 0; i < n - 3; i++) {
		if (s[i] == s[i + 1] && s[i + 3] == s[i] && s[i + 2] != s[i]) {
			ans -= 1;
		}
	}

	int ct = 0;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
			ct += 1;
		}
	}

	cout << ans - max(0ll, ct - 1) << "\n";
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