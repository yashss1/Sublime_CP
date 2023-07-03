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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	map<int, int> mp;
	vector<int> temp;
	temp.push_back(v[0]); mp[0] = 1;
	for (int i = k; i < n; i++) {
		temp.push_back(v[i]);
		mp[i] = 1;
	}

	for (int i = 1; i < k; i++) {
		if (i + k < n) {
			temp.push_back(v[i]);
			mp[i] = 1;
		}
	}
	sort(all(temp));

	int kk = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (mp[i] == 1) {
			ans[i] = temp[kk];
			kk++;
		}
		else {
			ans[i] = v[i];
		}
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
