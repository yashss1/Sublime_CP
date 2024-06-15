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
	vector<int> c, d;
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			c.push_back(s[i] - 'a');
		}
		else {
			d.push_back(s[i] - '0');
		}
	}

	for (int i = 1; i < n; i++) {
		if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i] >= '0' && s[i] <= '9') {
			cout << "NO\n";
			return;
		}
	}

	vector<int> c1, d1;
	c1 = c, d1 = d;
	sort(all(c));
	sort(all(d));

	if (c1 == c && d1 == d) {
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