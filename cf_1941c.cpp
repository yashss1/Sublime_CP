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

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i + 4 < n) {
			if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p' && s[i + 3] == 'i' && s[i + 4] == 'e') {
				ans++;
				i += 4;
				continue;
			}
		}
		if (i + 2 < n) {
			if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
				ans++;
				i += 2;
				continue;
			}
			if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
				ans++;
				i += 2;
				continue;
			}
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
	test
	yash();
	return 0;
}