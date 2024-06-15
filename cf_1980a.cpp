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
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}

	vector<int> temp;
	for (auto it : mp) {
		temp.push_back(it.second);
	}
	// sort(all(temp), greater<int>());

	temp = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int ans = 0;

	for (char i : temp) {
		ans += max(0ll, m - mp[i]);
	}
	cout << ans << "\n";
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