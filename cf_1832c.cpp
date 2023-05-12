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
	vector<int> v1(n), v;
	int prev = -1;
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
		if (prev != v1[i]) {
			v.push_back(v1[i]);
		}
		prev = v1[i];
	}

	n = v.size();

	int flag = 0;
	if (v[0] > v[1]) flag = 1;

	int ans = 2;
	for (int i = 1; i < n; i++) {
		if (v[i - 1] == v[i]) {
			continue;
		}

		if (v[i - 1] > v[i] && flag == 0) {
			ans++;
			flag ^= 1;
			continue;
		}

		if (v[i - 1] < v[i] && flag == 1) {
			ans++;
			flag ^= 1;
			continue;
		}


	}

	cout << ans << '\n';
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