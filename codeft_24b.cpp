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
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
	}
	vector<int> ans;

	int gone = n;
	int k = 0;
	map<int, int> mp2;
	for (int i = 0; i <= n; i++) {
		gone -= mp[k]; mp[k] = 0;
		ans.push_back(gone);
		if (gone == 0) {
			break;
		}
		gone--;
		// if (v[i] == i + 1) {
		// mp2[v[i]]++;
		// }
		// gone += (mp[i + 1] - mp2[i + 1]);
		// cout << i + 1 << " " << gone << '\n';
		// cout << mp[i + 1] << " " << mp2[i + 1] << '\n';
		while (mp[v[i]] == 0 && i < n)
			i++;
		if (i == n) break;

		mp[v[i]]--;
		k++;
	}


	pVec(ans);
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
