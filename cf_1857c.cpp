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
	int m = (n * (n - 1) / 2);
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	// pVec(v);

	vector<int> ans(n);
	int j = n - 1;
	int p = 0;
	for (int i = 0; i < m; i++) {
		int k = i + j - 1;
		j--;

		// cout << i << "\n";
		ans[p++] = v[i];
		i = k + 1;
		i--;
		if (j < 0) {
			break;
		}
	}
	ans[n - 1] = 1000000000;
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