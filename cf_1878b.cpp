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
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(3);

	for (int i = 3; i <= n; i++) {
		int t1 = ans[ans.size() - 1];
		int t2 = ans[ans.size() - 2];
		int curr = t1 + 1;
		if ((curr) % (t2 + t1) == 0) {
			curr += 1;
		}
		if ((curr + t1) % 3 == 0) {
			curr += 1;
		}
		ans.push_back(curr);
	}
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