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
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			v[i][j] = s[j] - '0';
		}
	}


	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		int p = i, q = i;
		if (v[0][i] == 1)
			for (int j = i + 1; j < n; j++) {
				mp[j] = {max(0ll, p), min(n - 1, q)};
				p--, q++;
			}
		break;
	}

	for (int i = 0; i < n; i++) {
		cout << i << " -> ";
		pVec(mp[i]);
	}
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