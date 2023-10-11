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
const int N = 5e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

long long getres(vector<int> &res, long long target) {
	int n1 = res.size();
	long long p = 0;
	int sum = 0;
	long long ans = 1e9;
	for (long long i = 0; i < n1; i++) {
		sum += res[i];
		while (sum > target) {
			sum -= res[p];
			p++;
		}
		if (sum == target) {
			ans = min(ans, (i - p) + 1);
		}
	}
	return ans;
}

int n;
vector<int> v(N);
vector<vector<int>> temp;

int go(int idx, int mex, vector<vector<int>> &dp) {
	if (idx == n - 1) {
		int curr = (temp[idx][1] - 1) * mex;
		return curr;
	}

	int &ans = dp[idx][mex];
	if (ans != -1) {
		return ans;
	}

	int c1 = 1e18, c2 = 1e18;
	if (temp[idx][0] < mex) {
		c1 = ((temp[idx][1] - 1) * mex) + temp[idx][0] + go(idx + 1, temp[idx][0], dp);
	}
	c2 = go(idx + 1, mex, dp);

	return ans = min(c1, c2);
}

void yash()
{

	cin >> n;
	set<int> st;
	for (int i = 0; i < n + 1; i++) {
		st.insert(i);
	}

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
		st.erase(v[i]);
	}

	int mex = (*st.begin());
	if (mex == 0) {
		cout << "0\n";
		return;
	}

	temp.clear();
	for (auto it : mp) {
		temp.push_back({it.first, it.second});
	}

	reverse(all(temp));
	n = temp.size();
	vector<vector<int>> dp(n, vector<int>(mex + 1, -1));

	cout << go(0, mex, dp) << endl;
	return;

	int ans = 1e18;
	for (auto it : mp) {
		// vector<int> temp = v;

		int curr = 0;
		curr += ((it.second - 1) * (mex));

		int tt = min(mex, it.first);
		curr += (mp[0] * tt);
		// cout << it.first << " -> " << curr << "\n";
		ans = min(ans, curr);
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