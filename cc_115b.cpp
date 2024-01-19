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
	vector<int> a(n), b(n);

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<int> poss;
	for (int i = 0; i < n; i++) {
		poss.push_back(a[0] + b[i]);
	}

	for (auto it : poss) {
		int flag = 1;
		int sum = it;

		map<int, int> temp = mp;
		for (int i = 0; i < n; i++) {
			int num = b[i];
			int want = sum - num;
			temp[want]--;
		}

		for (auto it2 : temp) {
			if (it2.second != 0) {
				flag = 0;
			}
		}

		if (flag == 0) {
			continue;
		}

		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int num = b[i];
			int want = sum - num;
			ans.push_back(want);
		}

		pVec(ans);
		pVec(b);
		return;
	}

	cout << "-1\n";
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