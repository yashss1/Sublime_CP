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

	int ans = 0, flag2 = 1, mx = 0;
	string temp;
	temp.push_back(s[0]);
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			ans++;
			flag2++;
		}
		else {
			mx = max(mx, flag2);
			flag2 = 1;
			temp.push_back(s[i]);
		}
	}

	if (s[0] == s[n - 1] && temp.size() > 1) {
		ans++;
		temp.pop_back();
	}

	int flag = 0;
	if (ans % 2) {
		flag ^= 1;
	}

	// cout << temp << " " << flag2 << '\n';

	if (temp.size() < 3) {
		if (mx < 3) {
			cout << "Bob\n";
			return;
		}
		cout << "Alice\n";
		return;
	}

	int k = temp.size() - 3;
	// cout << k << ' ' << flag << '\n';

	if (k % 2) {
		if (flag == 1) {
			cout << "Bob\n";
			return;
		}
		cout << "Alice\n";
		return;
	}
	if (flag == 0) {
		cout << "Bob\n";
		return;
	}
	cout << "Alice\n";
	return;

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