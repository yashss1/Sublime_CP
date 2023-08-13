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
	if (n % 3 == 1) {
		cout << "YES\n";
		return;
	}
	for (char c = 'a'; c <= 'z'; c++) {
		string temp = "";
		int t = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == c) {
				t %= 3;
				string ss(t, '#');
				temp += ss;
				temp.push_back(c);
				t = 0;
			}
			else {
				t++;
			}
		}
		t %= 3;
		string ss(t, '#');
		temp += ss;

		// cout << c << " -> " << temp << '\n';

		int c1 = -1, c2 = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == c) {
				int back = (i);
				int front = (n - i - 1);
				if (back % 3 == 0 && c1 == -1) {
					c1 = back;
				}
				if (front % 3 == 0) {
					c2 = back;
				}
			}
		}
		// cout << c << " -> " << c1 << " " << c2 << '\n';
		if (c1 != -1 && c2 != -1) {
			if (n % 3 == 2) {
				if (c1 < c2) {
					cout << "YES\n";
					return;
				}
			}
			else {
				if (c1 + 1 < c2) {
					cout << "YES\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
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