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
Find a string with ODD pattern than the rest of N-1 strings

INPUT:
2
5
ADC
BED
CFE
DGF
FGH
4
ABCD
BCDE
EFGH
DCBE

OUTPUT:
FGH
DCBE

*/

void yash()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<vector<int>> pattern(n);
	for (int i = 0; i < n; i++) {
		string s = v[i];
		vector<int> temp;
		for (int j = 1; j < s.size(); j++) {
			temp.push_back(s[j] - s[j - 1]);
		}
		pattern[i] = temp;
	}

	map<vector<int>, int> mp;
	for (auto it : pattern) {
		mp[it]++;
	}

	vector<int> res;
	for (auto it : mp) {
		if (it.second == 1) {
			res = it.first;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (pattern[i] == res) {
			cout << v[i] << '\n';
			break;
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
