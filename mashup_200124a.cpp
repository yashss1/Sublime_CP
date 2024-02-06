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

	int idx = 0;
	vector<int> ans;
	int t = 10;
	while (idx < n) {
		int mex = 0;

		// cout << "________ \n";
		// for (auto it : mp) {
		//     cout << it.first << " " << it.second << "\n";
		// }
		// cout << "________ \n";

		for (int i = 0; i <= n; i++) {
			if (mp[i] > 0) {

			}
			else {
				mex = i;
				break;
			}
		}

		set<int> tempMx;
		for (int i = 0; i < mex; i++) {
			tempMx.insert(i);
		}

		ans.push_back(mex);
		// cout << "tempsize " <<  tempMx.size()  << " " << mex << " " << idx << "\n";

		int temp = 0;
		for (int i = idx; i < n; i++) {
			tempMx.erase(v[i]);
			mp[v[i]]--;
			if (tempMx.size() == 0) {
				idx = i + 1;
				break;
			}
			temp = i;
		}

		// cout << idx << "\n";

		if (temp == n - 1) {
			break;
		}

	}


	cout << ans.size() << "\n";
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