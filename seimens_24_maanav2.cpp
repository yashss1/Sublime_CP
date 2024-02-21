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
INPUT:
3
3 2
1 3 5
5 2
1 5 3 4 2
6 2
2 4 6 8 10 12

OUTPUT:
2
3
5
*/

int countPairs(vector<int> v, int k) {
	int n = v.size();

	map<int, int> mp;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += mp[v[i] + k] + mp[v[i] - k];
		mp[v[i]]++;
	}
	return ans;
}

/*
INPUT:
2
wwwbbbbwww
wwwbb

OUTPUT:
bob
wendy
*/

string gameWinner(string s) {
	int n = s.size();
	int curr = 1;
	int a = 0, b = 0;

	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			curr++;
		}
		else {
			if (s[i - 1] == 'w') {
				a += max(0ll, curr - 2);
			}
			else {
				b += max(0ll, curr - 2);
			}
			curr = 1;
		}
	}
	if (s[n - 1] == 'w') {
		a += max(0ll, curr - 2);
	}
	else {
		b += max(0ll, curr - 2);
	}

	if (a > b) {
		return "wendy";
	}
	else {
		return "bob";
	}
}

void yash()
{
	// int n, k;
	// cin >> n >> k;
	// vector<int> v(n);
	// for (int i = 0; i < n; i++) {
	//     cin >> v[i];
	// }

	// cout << countPairs(v, k) << '\n';

	string s;
	cin >> s;

	cout << gameWinner(s) << '\n';
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