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
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] *= -1;
	}

	set<int> st;
	int sum = 0, ans = 0;
	int l = 0, r = 0;
	pair<int, int> temp = { -1, -1};

	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (sum < 0) {
			l = i + 1;
			sum = 0;
		}
		if (ans < sum) {
			ans = sum;
			r = i;
			while (l < n && v[l] < 0) l++;
			temp = {l, r};
		}
	}

	if (temp.first == -1) {
		cout << "0\n";
		return;
	}

	// cout << ans << '\n';
	// cout << temp.first << " " << temp.second << '\n';

	int res = 0;
	for (int i = 0; i < temp.first; i++) {
		res += (v[i] * -1);

	}
	cout << res << '\n';
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