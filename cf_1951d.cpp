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
	int n, k;
	cin >> n >> k;

	vector<int> ans;

	int rem = k;
	while (n > 0 && rem > 0) {
		int curr = (n / rem) + (n % rem != 0);
		int temp = n / curr;
		ans.push_back(curr);
		int taken = (temp * curr);
		rem -= (n / curr);
		n -= taken;
		cout << n  << " " << curr co << " " << rem << '\n';
	}

	if (rem != 0) {
		cout << "NO\n"; return;
	}
	cout << "YES\n";
	cout << ans.size() << '\n';
	pVec(ans);
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