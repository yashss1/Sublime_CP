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
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, nn;
string s;
vector<string> v(N);
vector<int> dp;

int go(int idx) {
	if (idx == nn) {
		return 1;
	}

	int &ans = dp[idx];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = 0; i < n; i++) {
		if (idx + v[i].size() > nn) {
			continue;
		}
		string temp = s.substr(idx, v[i].size());
		if (temp == v[i]) {
			ans |= go(idx + v[i].size());
		}
	}

	return ans;
}

void yash()
{
	cin >> s;
	nn = s.size();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	dp.assign(nn + 5, -1);
	if (go(0)) {
		cout << "YES\n"; return;
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