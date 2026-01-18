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

int solution1(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; i++) {
		set<int> st;
		string s = to_string(i);
		for (int j = 0; j < s.size(); j++) {
			st.insert(s[j]);
		}
		if (st.size() == 3) {
			ans++;
		}
	}
	return ans;
}

string solution2(vector<string> v) {
	int n = v.size();
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string s = v[i].substr(5, 2);
		mp[s]++;
	}
	string ans;
	int cnt = 0;
	for (auto it : mp) {
		if (cnt <= it.second) {
			ans = it.first;
			cnt = it.second;
		}
	}
	return ans;
}

int solution4(vector<int> v, int f) {
	int n = v.size();

	sort(v.begin(), v.end());

	int ans = 0;

	for (int i = 0; i < n; i++) {
		// l = v[i] - f, r = v[i] + f

		int l = 0, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (v[mid] >= (v[i] - f)) {
				r = mid - 1;
				res = mid;
			} else {
				l = mid + 1;
			}
		}

		int temp = (i - res) + 1;

		l = i, r = n - 1, res = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (v[mid] <= (v[i] + f)) {
				l = mid + 1;
				res = mid;
			} else {
				r = mid - 1;
			}
		}

		temp += (res - i);

		ans = max(ans, temp);
	}

	cout << ans << " ";

	int cnt = ans;
	for (int i = cnt - 1; i < n; i++) {
		int l = i - (cnt - 1), r = i;
		int temp = v[r] - f;
		if (v[l] + f >= temp) {
			return temp;
		}
	}

	return ans;
}

// int solution3(vector<vector<int>> v, int f) {
//     int n = v.size(), m = v[0].size();

//     for(int i = 0; i < n; i++) {

//     }
// }

void yash()
{
	// int l, r;
	// cin >> l >> r;
	// int ans = solution1(l, r);
	// cout << ans << '\n';

	// int n;
	// cin >> n;
	// vector<string> v(n);
	// for (int i = 0; i < n; i++) {
	//     cin >> v[i];
	// }
	// cout << solution2(v) << '\n';

	int n, f;
	cin >> n >> f;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << solution4(v, f) << '\n';
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