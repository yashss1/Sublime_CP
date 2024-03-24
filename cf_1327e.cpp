//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 998244353;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

map<int, int> mp;
void solve(string s) {
	map<int, int> temp;
	int curr = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			curr++;
		}
		else {
			temp[curr]++;
			curr = 1;
		}
	} temp[curr]++;
	// cout << s << "\n";
	for (auto it : temp) {
		mp[it.first] += it.second;
	}
}

int n;
void go(int idx, string s) {
	if (idx >= n) {
		solve(s);
		return;
	}
	for (char c = '0'; c <= '9'; c++) {
		string curr = s;
		curr.push_back(c);
		go(idx + 1, curr);
	}
}

int power(int a, int b)
{
	if (b == 0)
		return 1;
	else if (b % 2 == 0)
		return power((a * a) % MOD, b >> 1) % MOD;
	else
		return (a * power((a * a) % MOD, b >> 1) % MOD);
}


void yash()
{
	cin >> n;
	// go(0, "");
	// for (auto it : mp) {
	// 	cout << it.second << '\n';
	// 	// cout << it.first << " " << it.second << '\n';
	// }

	// only calculate for block 1 for i, ans for i + 1 it will be for block 2 ans so on..

	/*
	n = 4
	make block 1 at i = 1 -> 10 9 10 10 ..
	make block 1 at i = 2 -> 9 10 9 10 ..
	make block 1 at i = 3 -> 10 9 10 9 (10 .)
	make block 1 at i = 4 -> 10 10 9 10 (9 10 ..)
	*/

	vector<int> ans(n);
	ans[0] = 10;

	for (int i = 2; i <= n; i++) {
		int firstAndLast = 2 * ((power(10ll, i - 1) * 9) % MOD);
		int rem = (i - 2) * ((power(10ll, i - 2) * 81) % MOD);
		firstAndLast %= MOD;
		rem %= MOD;

		ans[i - 1] = firstAndLast + rem;
		ans[i - 1] %= MOD;
	}

	reverse(ans.begin(), ans.end());
	pVec(ans);
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