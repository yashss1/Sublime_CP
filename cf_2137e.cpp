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
	set<int> st;


	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> ans(n);
	int hehe = (k % 2 == 0) ? 4 : 5;
	int temp = min(hehe, k);
	while (temp--) {
		st.clear();
		for (int i = 0; i <= n; i++) {
			st.insert(i);
		}
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			mp[v[i]]++;
			if (st.find(v[i]) != st.end()) {
				st.erase(st.find(v[i]));
			}
		}
		int mx = (*st.begin());
		ans.assign(n, 0);
		for (int i = 0; i < n; i++) {
			if (mx <= v[i]) {
				ans[i] = mx;
			} else {
				if (mp[v[i]] == 1) {
					ans[i] = v[i];
				} else {
					ans[i] = mx;
				}
			}
		}

		// pVec(ans);
		v = ans;
	}


	int ansss = 0;
	for (auto it : ans) {
		ansss += it;
	}
	cout << ansss << '\n';
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