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

int n;
string s;

int go(int idx, int prev, int want, int off) {
	if (idx == n) {
		return 1;
	}

	int ans = 0;
	if (s[idx] == '1') {
		if (off == 1) {
			return 0;
		}
		if (want == 1) {
			ans |= go(idx + 1, 1, 0, 0);
		}
		else {
			ans |= go(idx + 1, 0, 1, 0);
			ans |= go(idx + 1, 1, 0, 0);
		}
		ans |= go(idx + 1, 0, 1, 0);
	}
	else {
		if (want == 1) {
			return 0;
		}
		go(idx + 1, 0, 0, 1);
	}
	return ans;
}

void yash()
{
	cin >> n;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			ans++;
		}
	}
	int flag = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == '1' && s[i - 1] == s[i]) {
			flag = 1;
		}
	}
	if (ans % 2 == 0) {
		if (ans == 2 && flag == 1) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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