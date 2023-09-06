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

	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') {
			st.push(1);
		}
		else if (s[i] == '-') {
			if (st.size() == 0) {
				cout << "NO\n"; return;
			}
			st.pop();
		}
		else if (s[i] == '1') {
		}
		else {
			if (st.size() <= 1) {
				cout << "NO\n"; return;
			}
		}
	}

	string curr = "", prev = "-1";
	char cc = '-';

	while (!st.empty()) {
		st.pop();
	}

	int szzz = 0;
	for (int i = 0; i < n; i++) {
		int fl = 0;
		if (s[i] == '1') {
			if (prev != "-1") {
				for (int j = 0; j < curr.size(); j++) {
					if (curr[j] == '+') {
						st.push(1);
					}
					else {
						if (st.size() == 0) {
							cout << "NO\n";
							return;
						}
						st.pop();
					}
					if (st.size() < szzz) {
						fl = 1;
					}
				}
				szzz = st.size();

				if (s[i] == cc) {
					continue;
				}
				if (fl == 0) {
					cout << "NO\n"; return;
				}

			}
			else {
				for (auto it : curr) {
					if (it == '+') {
						st.push(1);
					}
					else {
						if (st.size() == 0) {
							cout << "NO\n";
							return;
						}
						st.pop();
					}

				}
				szzz = st.size();
			}

			prev = curr;
			curr = "";
			cc = s[i];
			continue;
		}
		if (s[i] == '0') {
			if (prev != "-1") {
				int goneback = 0;
				for (int j = 0; j < curr.size(); j++) {
					if (curr[j] == '-') {
						if (st.size() == 0) {
							cout << "NO\n";
							return;
						}
						st.pop();
						if (st.size() < szzz) {
							goneback = 1;
						}
					}
					else {
						fl = 1;
						st.push(1);
					}
				}

				if (s[i] == cc) {
					continue;
				}

				if (szzz == st.size()) {
					if (goneback == 0) {
						cout << "NO\n"; return;
					}
				}
				if (szzz > st.size()) {
					cout << "NO\n"; return;
				}

				szzz = st.size();
			}
			else {
				for (auto it : curr) {
					if (it == '+') {
						st.push(1);
					}
					else {
						if (st.size() == 0) {
							cout << "NO\n";
							return;
						}
						st.pop();
					}

				}
				szzz = st.size();
			}
			prev = curr;
			curr = "";
			cc = s[i];
			continue;
		}
		curr.push_back(s[i]);
	}


	// // pVec(temp);
	// for (int i = 1; i < temp.size(); i++) {
	// 	// string curr = temp[i];
	// 	// int idx1 = -1, idx2 = -1;
	// 	// for (int j = 0; j < curr.size(); j++) {
	// 	// 	if (curr[j] == '-') {
	// 	// 		idx1 = j;
	// 	// 		break;
	// 	// 	}
	// 	// }
	// 	// for (int j = 0; j < curr.size(); j++) {
	// 	// 	if (curr[j] == '+') {
	// 	// 		idx2 = j;

	// 	// 	}
	// 	// }
	// 	// if (idx1 == -1 || idx2 == -1 || idx1 > idx2) {
	// 	// 	cout << "NO\n"; return;
	// 	// }
	// 	if (temp[i][0] != '-') {
	// 		cout << "NO\n"; return;
	// 	}
	// }
	cout << "YES\n";
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