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
	sort(v.begin(), v.end());

	int k = n - 1;
	while (k >= 0) {
		int t = v[k];
		if (mp[t] > 0) {
			int flag = 0;
			for (int i = t; i >= 0; i--) {
				if (mp[i] == 0) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				for (int i = t; i >= 0; i--) {
					mp[i]--;
				}
				ans.push_back(t + 1);
			}
		}
		k--;
	}


	vector<int> temp;
	for (int i = 0; i <= n; i++) {
		if (mp[i] > 0) {
			for (int j = 0; j < mp[i]; j++) {
				temp.push_back(i);
			}
		}
	}


	// pVec(temp);
	for (int i = 0; i < temp.size(); i++) {
		ans.push_back(0);
	}
	cout << ans.size() << '\n';
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