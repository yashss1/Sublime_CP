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

// KMP algo
/*
abcabcd
abasabcabcd
-> 4

Questions
https://leetcode.com/problems/shortest-palindrome/description/
*/

vector<int> lpsFunction(string s) {
	int n = s.size();
	int i = 0, j = 1;
	vector<int> lps(n, 0);
	while (j < s.size()) {
		if (s[i] == s[j]) {
			i++;
			lps[j] = i;
			j++;
		}
		else {
			if (i != 0) {
				i = lps[i - 1];
			}
			else {
				lps[j] = 0;
				j++;
			}
		}
	}
	return lps;
}

int kmp(string s, string t, vector<int> &prefix) {
	int i = 0, j = 0, pos = -1, occurences = 0;
	while (i < t.size()) {
		if (t[i] == s[j]) {
			j++, i++;
		}
		else {
			if (j != 0) {
				j = prefix[j - 1];
			}
			else {
				i++;
			}
		}
		if (j == s.size()) {
			pos = i - s.size();
			occurences++;
		}
	}
	return occurences;
}

void yash()
{
	string s, t;
	cin >> s >> t;
	vector<int> prefix = lpsFunction(s);
	// pVec(prefix);
	int pos = kmp(s, t, prefix);
	cout << pos << '\n';
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