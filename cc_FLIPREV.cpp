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
	string a, b;
	cin >> a >> b;

	string temp;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			temp.push_back('0');
		} else {
			temp.push_back('1');
		}
	}

	vector<vector<int>> ans;
	int start = -1;
	for (int i = 0; i < n; i++) {
		if (temp[i] == '1' && start == -1) {
			start = i;
		} else if (temp[i] == '0') {
			if (start == -1) {
				continue;
			}
			ans.push_back({1, start + 1, i});
			start = -1;
		}
	}
	if (start != -1) {
		ans.push_back({1, start + 1, n});
	}

	cout << ans.size() << "\n";
	for (auto it : ans) {
		pVec(it);
	}
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