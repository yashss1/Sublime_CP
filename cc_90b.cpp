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
	map<char, int> mp;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}

	int res = 0;
	vector<char> temp;
	for (auto it : mp) {
		if (it.second % 2 == 1) {
			res++;
			temp.push_back(it.first);
		}
	}

	if (res > 1) {
		cout << "0\n";
		return;
	}

	if (res == 1) {
		char cc = temp[0];
		vector<char> vv;
		for (char c = 'a'; c <= 'z'; c++) {
			if (c == cc) {
				continue;
			}

			if (mp[c] != 0) {
				vv.push_back(c);
			}
		}

		if (vv.size() >= 1) {
			cout << "1\n";
			return;
		}

		cout << "2\n";
		return;
	}

	cout << "1\n";
	return;

	vector<char> vv;
	for (char c = 'a'; c <= 'z'; c++) {
		if (mp[c] != 0) {
			vv.push_back(c);
		}
	}

	if (vv.size() > 1) {
		cout << "2\n";
		return;
	}

	if (mp[vv[0]] <= 2) {
		cout << "1\n";
		return;
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