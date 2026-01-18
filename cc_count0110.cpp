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

pair<int, int> count01_10(string s) {
	int n = s.size();

	map<int, int> mp;
	int zeroOne = 0, oneZero = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			oneZero += (mp['1']);
		} else {
			zeroOne += (mp['0']);
		}
		mp[s[i]]++;
	}
	return {zeroOne, oneZero};
}

string toBinary(int n, int sz)
{
	string r;
	while (n != 0) {r = (n % 2 == 0 ? "0" : "1") + r; n /= 2;}
	reverse(r.begin(), r.end());
	while (r.size() < sz) {
		r.push_back('0');
	}
	reverse(r.begin(), r.end());
	return r;
}

void yash()
{
	int n;
	cin >> n;

	// map<int, int> mp;
	// for (int i = 0; i < pow(2, n); i++) {
	//   string bin = toBinary(i, n);
	//   pair<int, int> temp = count01_10(bin);
	//   // cout << bin << " -> " << temp.first << " " << temp.second << " = " << (temp.first + temp.second) << '\n';
	//   mp[temp.first + temp.second]++;
	// }
	// cout << n << "\n";
	// for (auto it : mp) {
	//   cout << it.first << " " << it.second << '\n';
	// }

	map<int, int> uniques;
	for (int i = 0; i <= n; i++) {
		uniques[i * (n - i)]++;
	}

	int ans = 0;
	for (auto it : uniques) {
		// cout << it.first << " " << it.second << '\n';
		ans += it.first + 1;
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