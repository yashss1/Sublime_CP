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
	string s;
	cin >> s;

	int res = 0;
	vector<int> pref(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + (s[i] == 'O');
		if (s[i] == 'O') res++;
	}

	// pVec(pref);

	if (res == n) {
		cout << "0 0\n";
		return;
	}

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int l = i, r = i + res - 1;
		if (r > n - 1) {
			break;
		}


		int os = pref[r + 1] - pref[l];
		int curr = res - os;
		// cout << l << " " << r << " -> ";
		// cout << curr << "\n";
		mp[curr]++;
	}

	vector<pair<int, int>> ans;
	for (auto it : mp) {
		ans.push_back({it.first, it.second});
	}
	sort(ans.begin(), ans.end());


	cout << ans[0].first << " " << ans[0].second << '\n';
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}