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

	int a = 0, b = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			a++;
		}
		else {
			b++;
		}
	}

	string res = "";
	for (int i = 0; i < a; i++) {
		res += "(";
	}
	for (int i = 0; i < b; i++) {
		res += "(";
	}
	for (int i = 0; i < a; i++) {
		res += ")";
	}
	for (int i = 0; i < b; i++) {
		res += ")";
	}



	// cout << res << "\n";
	if (s == "()") {
		cout << "NO\n"; return;
	}
	cout << "YES\n";

	string res2 = "";
	for (int i = 0; i < n; i++) {
		res2 += "()";
	}

	int fl = 0;
	for (int i = 0; i < 2 * n; i++) {
		string p;
		for (int j = i; j < 2 * n; j++) {
			p.push_back(res[j]);
			if (p == s) {
				fl = 1;
			}
		}
	}
	if (fl == 0) {
		cout << res << '\n';
		return;
	}
	cout << res2 << "\n";

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