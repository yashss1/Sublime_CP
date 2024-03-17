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
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	if (s[a - 1] == s[b - 1]) {
		cout << "0\n";
		return;
	}
	cout << "1\n"; return;

	if (a > b) {
		swap(a, b);
	}


	a--, b--;

	vector<int> ans;
	for (int i = a + 1; i < b; i++) {
		if (s[i] != s[a]) {
			ans.push_back(i - a);
			break;
		}
	}
	for (int i = b - 1; i > a; i--) {
		if (s[i] != s[b]) {
			ans.push_back(b - i);
			break;
		}
	}

	if (ans.size() != 0) {
		cout << min(ans[0], ans[1]) << '\n';
		return;
	}

	for (int i = 0; i < a; i++) {
		if (s[i] != s[a]) {
			ans.push_back((a - i) + (b - i));
		}
	}
	for (int i = b + 1; i < n; i++) {
		if (s[i] != s[a]) {
			ans.push_back((i - a) + (i - b));
		}
	}

	if (ans.size() != 0) {
		cout << min(ans[0], ans[1]) << '\n';
		return;
	}
	assert(false);

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