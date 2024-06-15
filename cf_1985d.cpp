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
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<int>> temp;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int curr = 0;
		int a = -1, b = -1;
		for (int j = 0; j < m; j++) {
			v[i][j] = s[j];
			if (s[j] == '#') {
				if (a == -1) {
					a = j;
				} curr++;
				b = j;
			}
		}
		temp.push_back({curr, a, b});
		mx = max(mx, curr);
	}

	for (int i = 0; i < n; i++) {
		if (temp[i][0] == mx) {
			int a = temp[i][1], b = temp[i][2];
			cout << i + 1 << " " << ((b + a) / 2) + 1 << '\n';
			return;
		}
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