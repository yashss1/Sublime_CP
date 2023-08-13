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

/*
3
cdecd
4
0 0 0 0
0 1 2 3
0 1 1 0
xxdnssuqevu
1
0
10
3
bcba
3
1 2 1
3 3 1
2 0 0
*/

void yash()
{
	// INPUT
	string s;
	cin >> s;
	int m = s.size();
	int n;
	cin >> n;
	vector<int> startIndex(n), endIndex(n), subs(n);
	for (int i = 0; i < n; i++) {
		cin >> startIndex[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> endIndex[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> subs[i];
	}


	// CODE
	vector<vector<int>> hsh(26, vector<int>(m + 1, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			hsh[j][i + 1] = hsh[j][i];
		}
		hsh[s[i] - 'a'][i + 1] += 1;
	}


	string ans = "";
	for (int i = 0; i < n; i++) {
		int l = startIndex[i] + 1, r = endIndex[i] + 1;
		int temp = 0;
		for (int j = 0; j < 26; j++) {
			int curr = hsh[j][r] - hsh[j][l - 1];
			if (curr % 2 == 1) {
				temp++;
			}
		}

		temp /= 2;
		if (temp <= subs[i]) {
			ans += "1";
		}
		else {
			ans += "0";
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
	test
	yash();
	return 0;
}