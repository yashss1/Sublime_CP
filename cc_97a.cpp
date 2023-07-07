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

	int fl = 0;
	int ans = 0, taken = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == ':' && fl == 1) {
			if (taken == 1) {
				ans++;
			}
			taken = 0;
			continue;
		}
		if (s[i] == ':' && fl == 0) {
			fl = 1;
			continue;
		}
		if (s[i] == ')' && fl == 1) {
			taken = 1;
			continue;
		}
		fl = 0;
		taken = 0;
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