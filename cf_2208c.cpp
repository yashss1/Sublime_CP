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

vector<pair<int, int>> v;

int go(int idx) {
	return 0;
}

void yash()
{
	int n;
	cin >> n;
	v.clear();
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	// umm magcha dependent tr ahe, umm
	double ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		double newPower = ((1 - (v[i].second / (100.00))) * ans);
		double take = v[i].first + newPower;
		// double newPower =  take * ans;
		ans = max(ans, take);
	}

	cout << fixed << setprecision(9) << ans << '\n';
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