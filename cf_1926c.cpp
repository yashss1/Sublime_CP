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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> ans(N, 0);
void solve(int n) {
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		int sum = 0;
		for (int j = 0; j < s.size(); j++) {
			sum += (s[j] - '0');
		}
		ans[i] = ans[i - 1] + sum;
	}
}

void yash()
{
	int n;
	cin >> n;

	cout << ans[n] << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve(N);
	test
	yash();
	return 0;
}