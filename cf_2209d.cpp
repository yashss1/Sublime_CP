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

bool isValid(string &s, char c) {
	if (!s.empty() && s.back() == c) return false;
	if (s.size() >= 3 && s[s.size() - 3] == c) return false;
	return true;
}

string go(int r, int g, int b, bool rev) {
	string s = "";

	while (true) {
		vector<pair<int, char>> v = {
			{r, 'R'}, {g, 'G'}, {b, 'B'}
		};
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		int flag = 0;

		for (int i = 0; i < 2; i++) {
			char c1 = v[i].second;
			char c2 = v[i + 1].second;

			if (v[i].first == 0 || v[i + 1].first == 0) continue;

			if (!rev) {
				if (isValid(s, c1)) {
					s.push_back(c1);
					if (c1 == 'R') r--;
					else if (c1 == 'G') g--;
					else b--;

					if (isValid(s, c2)) {
						s.push_back(c2);
						if (c2 == 'R') r--;
						else if (c2 == 'G') g--;
						else b--;
					}
					flag = 1;
					break;
				}

				if (isValid(s, c2)) {
					s.push_back(c2);
					if (c2 == 'R') r--;
					else if (c2 == 'G') g--;
					else b--;

					if (isValid(s, c1)) {
						s.push_back(c1);
						if (c1 == 'R') r--;
						else if (c1 == 'G') g--;
						else b--;
					}
					flag = 1;
					break;
				}
			} else {
				if (isValid(s, c2)) {
					s.push_back(c2);
					if (c2 == 'R') r--;
					else if (c2 == 'G') g--;
					else b--;

					if (isValid(s, c1)) {
						s.push_back(c1);
						if (c1 == 'R') r--;
						else if (c1 == 'G') g--;
						else b--;
					}
					flag = 1;
					break;
				}

				if (isValid(s, c1)) {
					s.push_back(c1);
					if (c1 == 'R') r--;
					else if (c1 == 'G') g--;
					else b--;

					if (isValid(s, c2)) {
						s.push_back(c2);
						if (c2 == 'R') r--;
						else if (c2 == 'G') g--;
						else b--;
					}
					flag = 1;
					break;
				}
			}
		}

		if (flag) continue;

		flag = 0;
		for (auto it : v) {
			if (it.first == 0) continue;
			if (isValid(s, it.second)) {
				s.push_back(it.second);
				if (it.second == 'R') r--;
				else if (it.second == 'G') g--;
				else b--;
				flag = 1;
				break;
			}
		}

		if (flag == 0) break;
	}

	return s;
}

void yash()
{
	int r, g, b;
	cin >> r >> g >> b;

	string s1 = go(r, g, b, false);
	string s2 = go(r, g, b, true);

	if (s1.size() > s2.size()) cout << s1 << '\n';
	else cout << s2 << '\n';
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