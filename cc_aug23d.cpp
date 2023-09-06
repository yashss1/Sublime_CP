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

	string cc = "codechef", duplicate = s;
	string ans(8, '.');

	sort(all(duplicate));

	map<char, int> mp;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}

	// duplicate += duplicate;

	// cout << duplicate << "\n" << s << '\n';

	int idx = 0;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		while (1) {
			if (mp[duplicate[idx]] > 0 && duplicate[idx] != s[i] && cc[idx] != s[i]) {
				ans[i] = (duplicate[idx]);
				mp[duplicate[idx]]--;
				break;
			}
			idx++;
			if (idx == duplicate.size()) {
				idx = 0;
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

/*
codecook
codechef

keococdo


d...e...
dc..eck.
dcooecko
codechef


*/