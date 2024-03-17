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

int n, m, k, d;
vector<vector<int>> v;

vector<int> solve(vector<int> x) {
	multiset<int> st;
	vector<int> ans(m, INT_MAX);
	st.insert(1);
	ans[0] = 1;
	for (int i = 1; i < m; i++) {
		if (i - d - 2  >= 0) {
			int Todelete = ans[i - d - 2];
			st.erase(st.find(Todelete));
		}
		int mn = (*st.begin());
		ans[i] = x[i] + mn + 1;
		st.insert(ans[i]);
	}
	return ans;
}

void yash()
{
	cin >> n >> m >> k >> d;
	v.assign(n + 1, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	vector<int> res;
	for (int i = 0; i < n; i++) {
		vector<int> ans = solve(v[i]);
		// pVec(ans);
		res.push_back(ans[m - 1]);
	}

	int sum = 0, ans = 0;
	for (int i = 0; i < k; i++) {
		sum += res[i];
	}
	ans = sum;

	for (int i = k; i < n; i++) {
		sum -= res[i - k];
		sum += res[i];
		ans = min(ans, sum);
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