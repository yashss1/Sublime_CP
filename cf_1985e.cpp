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
	int x, y, z, k;
	cin >> x >> y >> z >> k;

	int nx = (x + 1) / 2;
	int ny = (y + 1) / 2;
	int nz = (z + 1) / 2;
	set<vector<int>> st;

	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			if ((k % (i * j)) == 0) {
				nz = k / (i * j);
				// if (nz <= z) {
				// 	vector<int> v = {i, j, nz};
				// 	sort(all(v));
				// 	st.insert(v);
				// }
				break;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			int temp = i * j * (k / (i * j));
			if (temp == k) {
				int temp2 = (z - ((k / (i * j))) + 1);
				int res = (x - i + 1) * (y - j + 1) * temp2;
				ans = max(ans, res);
			}
		}
	}
	cout << ans << "\n";
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