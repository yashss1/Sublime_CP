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
2 tgxnuasvfphkleozidjbwcqyrm
Mfdvn:_Qi_xoe'yn_fmm_yqbka,_aknd_gfx_goznakqdb.
Zqf:_Goznakqdb.

ans
Lance: If you're all right, then say something.
Mia: Something.

*/

void yash()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	map<char, char> mp;
	cout << s.size() << '\n';

	for (char c = 'a'; c <= 'z'; c++) {
		mp[c] = s[c - 'a'];
		mp[c - 32] = s[c - 'a'] - 32;
	}

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		string ans = "";
		for (int j = 0; j < a.size(); j++) {
			if (mp.find(a[j]) == mp.end()) {
				if (a[j] == '_') {
					ans.push_back(' ');
				}
				else {
					ans.push_back(a[j]);
				}
				continue;
			}
			ans.push_back(mp[a[j]]);
		}
		cout << ans << '\n';
	}

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