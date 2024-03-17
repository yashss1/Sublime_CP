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
	vector<int> v(n);

	map<int, int> first, last, mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (first[v[i]] == 0) {
			first[v[i]] = i + 1;
		}
		last[v[i]] = i + 1;
		mp[v[i]]++;
	}

	int mx = 0;
	for (auto it : mp) {
		mx = max(mx, it.second);
	}

	// int i = 0, j = 0;
	// map<int, int> temp;

	vector<vector<int>> ans;
	// while (j < n) {
	// 	temp[v[j]]++;
	// 	if (temp[v[j]] == mx) {
	// 		while (i <= j) {
	// 			if (v[i] != v[j]) {
	// 				temp[v[i]]--;
	// 				i++;
	// 			}
	// 			else {
	// 				break;
	// 			}
	// 		}
	// 		ans.push_back({(j - 1 + 1) , i + 1, j + 1});
	// 	}
	// 	j++;
	// }
	// sort(all(ans));


	for (auto it : first) {
		int l = first[it.first], r = last[it.first];
		if (mp[it.first] != mx) continue;
		ans.push_back({r - l + 1, l, r});
	}

	sort(all(ans));
	cout << ans[0][1] << ' ' << ans[0][2] << '\n';

}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}

