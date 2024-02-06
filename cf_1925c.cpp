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
	int n, k, m;
	cin >> n >> k >> m;
	string s;
	cin >> s;

	map<char, int> mp;
	for (int i = 0; i < m; i++) {
		mp[s[i]]++;
	}

	for (int i = 0; i < k; i++) {
		char c = (char)(i + 'a');
		if (mp[c] < n) {
			cout << "NO\n";
			string ans(n, c);
			cout << ans << '\n';
			return;
		}
	}

	map<char, int> temp;
	string ans;

	for (int j = 0; j < m; j++) {
		int flag = 1;
		temp[s[j]]++;
		for (int i = 0; i < k; i++) {
			char c = (char)(i + 'a');
			if (temp[c] == 0) {
				flag = 0;
			}
		}
		if (flag == 1) {
			for (int i = j; i >= 0; i--) {
				if (s[i] - 'a' < k) {
					ans.push_back(s[i]);
					break;
				}
			}
			temp.clear();
		}
	}

	if (ans.size() == n) {
		cout << "YES\n";
		return;
	}

	for (int i = 0; i < k; i++) {
		char c = (char)(i + 'a');
		if (temp[c] == 0) {
			ans.push_back(c);
			break;
		}
	}

	while (ans.size() < n) {
		ans.push_back((char)((k - 1) + 'a'));
	}

	cout << "NO\n";
	cout << ans << '\n';
	// cout << '\n';
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