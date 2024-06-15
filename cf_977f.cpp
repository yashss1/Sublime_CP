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

map<int, int> compressVector(vector<int>&v) {
	int n = v.size();
	vector<int> a = v;
	sort(a.begin(), a.end());

	map<int, int> mp, regain;
	int k = 2;
	mp[a[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > 1) {
			k++;
		}
		if (mp[a[i]] == 0) {
			mp[a[i]] = k;
			regain[k] = a[i];
			k++;
		}
	}

	for (int i = 0; i < n; i++) {
		v[i] = mp[v[i]];
	}
	return regain;
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	map<int, int> regain = compressVector(v);

	// pVec(v);

	vector<int> dp(2 * (n + 1), 1);
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		st.insert(v[i]);
		auto smallBiggestNumber = st.lower_bound(v[i]);
		if (smallBiggestNumber == st.begin()) {
			continue;
		}
		smallBiggestNumber--;

		if (*(smallBiggestNumber) != v[i] - 1) continue;
		dp[v[i]] = dp[*(smallBiggestNumber)] + 1;

		// cout << v[i] << " -> " << (*smallBiggestNumber) << " " << dp[v[i]] << '\n';
	}

	// pVec(dp);
	int ans = (*max_element(dp.begin(), dp.end()));
	// cout << ans << '\n';

	int endingAt = 0;
	vector<int> res, res2;
	for (int i = 0; i < n; i++) {
		if (dp[v[i]] == ans) {
			endingAt = v[i];
			break;
		}
	}
	int startingAt = endingAt - ans + 1;

	for (int i = 0; i < n; i++) {
		if (startingAt == v[i] && startingAt <= endingAt) {
			res.push_back(i + 1);
			res2.push_back(v[i]);
			startingAt++;
		}
	}

	cout << ans << '\n';
	// if (ans == 9) {
	// 	for (auto it : res2) {
	// 		cout << regain[it] << " ";
	// 	} cout << '\n';
	// 	pVec(res2);
	// }
	pVec(res);
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