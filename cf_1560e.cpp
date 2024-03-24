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

string validator(string s, string b) {
	string final = s;
	for (int i = 0; i < b.size(); i++) {
		string curr;
		for (int j = 0; j < s.size(); j++) {
			if (b[i] == s[j]) {

			}
			else {
				curr.push_back(s[j]);
			}
		}
		s = curr;
		final += curr;
	}
	return final;
}

void yash()
{
	string s;
	cin >> s;
	int n = s.size();

	set<char> st;
	string b;

	map<char, int> mp;
	vector<vector<int>> pref(26, vector<int>(n + 1, 0));

	for (int i = 0; i < n; i++) {
		mp[s[i]] = i;
		for (int j = 0; j < 26; j++) {
			pref[j][i + 1] = pref[j][i];
		}
		pref[s[i] - 'a'][i + 1]++;
	}

	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		if (st.find(s[i]) == st.end()) {
			b.push_back(s[i]);
			st.insert(s[i]);
		}
	}
	reverse(s.begin(), s.end());
	reverse(b.begin(), b.end());

	if (b.size() == 1) {
		cout << s << ' ' << s[0] << '\n';
		return;
	}

	// cout << b << '\n';
	// cout << mp[b[0]] << " " << mp[b[1]] << '\n';

	// for (int i = 0; i < 26; i++) {
	//     cout << (char)('a' + i) << " -> ";
	//     pVec(pref[i]);
	// }

	vector<int> occur(26, 0);
	for (int i = 0; i < b.size(); i++) {
		int times = pref[b[i] - 'a'][n] / (i + 1);
		occur[b[i] - 'a'] = times;
	}

	// for (int i = 0; i < 26; i++) {
	//     cout << (char)('a' + i) << " -> " << occur[i] << "\n";
	// }

	for (int i = 0; i < n; i++) {
		occur[s[i] - 'a']--;
		int flag = 0;
		for (int j = 0; j < 26; j++) {
			if (occur[j] > 0) {
				flag = 1;
			}
		}
		if (flag == 0) {
			if (validator(s.substr(0, i + 1), b) != s) {
				cout << "-1\n";
				return;
			}
			cout << s.substr(0, i + 1) << ' ' << b << "\n";
			return;
		}
	}
	cout << "-1\n"; return;
	// assert(false);
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