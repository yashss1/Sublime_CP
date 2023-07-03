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

// Z algo
/*
Questions:
//
https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/practice-problems/algorithm/prefix-number-f5c76976/
https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/practice-problems/algorithm/cyclic-permutations-15/

*/

/*
abc
abcabdabc
-> 2
*/

vector<int> zFunction(string s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r) {
			// when you already have this calculated -> inside zbox
			z[i] = min(r - i, z[i - l]);
		}

		// z[i] will be always zero here
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i]; // new boundary for zbox
		}
	}
	return z;
}

void yash()
{
	string s, t;
	cin >> s >> t;
	int k = s.size();
	s += "#";
	s += t;
	vector<int> prefix = zFunction(s);

	// pVec(prefix);

	int ans = 0;
	for (int i = k; i < prefix.size(); i++) {
		if (prefix[i] == k) {
			ans++;
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
	// test
	yash();
	return 0;
}