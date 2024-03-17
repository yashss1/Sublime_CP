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

int give_ans(int n) {
	// cout << n << " -> ";
	int ans = (n * (n + 1) / 2);
	ans--;
	return ans;
}

// source - https://cp-algorithms.com/string/manacher.html
vector<int> manacher_odd(string s) {
	int n = s.size();
	s = "$" + s + "^";
	vector<int> p(n + 2);
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = max(0ll, min(r - i, p[l + (r - i)]));
		while (s[i - p[i]] == s[i + p[i]]) {
			p[i]++;
		}
		if (i + p[i] > r) {
			l = i - p[i], r = i + p[i];
		}
	}
	return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
	string t;
	for (auto c : s) {
		t += string("#") + c;
	}
	auto res = manacher_odd(t + "#");
	return vector<int>(begin(res) + 1, end(res) - 1);
}

void yash()
{
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	vector<vector<int>> pref(26, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			pref[j][i + 1] += pref[j][i];
		}
		pref[s[i] - 'a'][i + 1]++;
	}

	// for (char c = 'a'; c <= 'z'; c++) {
	// 	pVec(pref[c - 'a']);
	// }

	vector<int> temp = manacher(s);
	for (auto &it : temp) {
		it--;
	}
	// pVec(temp);


	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		if (s[l] != s[r]) {
			cout << give_ans(r - l + 1) << '\n';
			continue;
		}
		if (pref[s[l] - 'a'][r + 1] - pref[s[l] - 'a'][l] == (r - l + 1)) {
			cout << "0\n";
			continue;
		}

		// check if s[l..r] is pal, if yes print n - 1, else print n
		int sz = (r - l + 1);
		if (sz % 2 == 1) {
			int mid = (sz / 2) + l;
			// cout << mid << " -> " << temp[mid * 2] << '\n';
			if (temp[mid * 2] >= (sz)) {
				cout << give_ans(sz - 1) << '\n';
				continue;
			}
			cout << give_ans(sz) << '\n';
			continue;
		}

		int mid = (sz / 2) + l;
		// cout << sz << " " << mid << '\n';
		if (temp[mid * 2 - 1] >= (sz)) {
			cout << give_ans(sz - 1) << '\n';
			continue;
		}
		cout << give_ans(sz) << '\n';
	}

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