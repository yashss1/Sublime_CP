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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<vector<int>> ans;
	int i = 0, j = 0;
	int sum = k;
	while (j < n) {
		int curr = sum + v[j];
		while (i <= j && curr < 0) {
			curr -= v[i];
			i++;
		}
		// cout << i << " " << j << '\n';
		ans.push_back({ -(j - i + 1), i, j});
		sum = curr;
		j++;
	}
	sort(ans.begin(), ans.end());

	if (ans.size() == 0) {
		cout << "-1\n";
		return;
	}
	if (ans[0][1] > ans[0][2]) {
		cout << "-1\n";
		return;
	}
	cout << ans[0][1] + 1 <<  " " << ans[0][2] + 1 << '\n';

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