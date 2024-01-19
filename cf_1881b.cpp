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
	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	if ((v[1] % v[0]) != 0 || (v[2] % v[0]) != 0) {
		cout << "NO\n";
		return;
	}

	int ans = (v[1] / v[0]) + (v[2] / v[0]);

	if (ans <= 5) {
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