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
	int n, l, r, s;
	cin >> n >> l >> r >> s;

	int k = (r - l + 1);
	int mn = (k * (k + 1) / 2);
	int mx = (k * (2 * n + 1 - k) / 2);

	if (s > mx || s < mn) {
		cout << "-1\n";
		return;
	}

	for (int i = 1; i + (r - l) <= n; i++) {
		int sum = 0;
		for (int j = l; j <= r; j++) {
			sum += i + (j - l);
		}

		if (sum > s || s - sum > r - l + 1) continue;
		int add = r - (s - sum) + 1;
		set<int> st;
		for (int j = 0; j < n; j++) {
			st.insert(j + 1);
		}

		// cout << s - sum << " " << i << " " << add << " -> ";
		vector<int> ans(n + 1, -1);
		for (int j = l; j <= r; j++) {
			ans[j] = i + (j - l);
			// cout << "\n" << ans[j] << " -> ";
			if (j >= add) {
				// cout << j << " " << add << '\n';
				ans[j]++;
			}
			// cout << ans[j] << '\n';
			st.erase(st.find(ans[j]));
		}
		// pVec(ans);
		if (ans[r] > n) continue;

		vector<int> temp(st.begin(), st.end());
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if (j >= l && j <= r) {

			}
			else {
				ans[j] = temp[p];
				p++;
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		} cout << '\n';
		return;
	}
	assert(false);
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