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

int solve(vector<vector<char>> &v, char c) {
	for (int i = 0; i < 3; i++) {
		int flag = 1;
		for (int j = 0; j < 3; j++) {
			if (v[i][j] != c) {
				flag = 0;
			}
		}
		if (flag == 1) {
			return 1;
		}
	}

	for (int i = 0; i < 3; i++) {
		int flag = 1;
		for (int j = 0; j < 3; j++) {
			if (v[j][i] != c) {
				flag = 0;
			}
		}
		if (flag == 1) {
			return 1;
		}
	}

	int flag = 1;
	for (int i = 0, j = 0; i < 3 && j < 3; i++, j++) {
		if (v[i][j] != c) {
			flag = 0;
		}
	}
	if (flag == 1) {
		return 1;
	}

	flag = 1;
	for (int i = 2, j = 2; i >= 0 && j >= 0; i--, j--) {
		if (v[i][j] != c) {
			flag = 0;
		}
	}

	return flag;
}

void yash()
{
	vector<vector<char>> v(3, vector<char>(3));
	vector<char> res;
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 3; j++) {
			v[i][j] = s[j];
		}
	}

	char ans = '#';
	for (int i = 0; i < 3; i++) {
		if (v[i][0] == v[i][1] and v[i][0] == v[i][2]) {
			ans = v[i][0];
		}
	}

	for (int i = 0; i < 3; i++) {
		if (v[0][i] == v[1][i] and v[1][i] == v[2][i]) {
			ans = v[0][i];
		}
	}

	if (v[0][0] == v[1][1] and v[0][0] == v[2][2])
		ans = v[0][0];

	if (v[0][2] == v[1][1] and v[0][2] == v[2][0])
		ans = v[0][2];

	if (ans == '#' || ans == '.') {
		cout << "DRAW\n";
		return;
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