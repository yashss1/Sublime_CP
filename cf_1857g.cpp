//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int go(int num, int idx, int n, vector<int> &v, int l, int r) {
	if (idx == n) {
		return 1;
	}

	int temp = num - v[idx];
	if (temp > r || temp < l) {
		return 0;
	}
	return go(temp, idx + 1, n, v, l, r);
}

void yash()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int l, r;
	cin >> l >> r;


	int i = l, j = r;
	int ans1 = -1, ans2 = -1;
	while (i <= j) {
		int mid = (i + j) / 2;
		cout << mid << '\n';
		if (go(mid, 0, n, v, l, r)) {
			j = mid - 1;
			ans1 = mid;
		}
		else {
			i = mid + 1;
		}
	}

	i = l, j = r;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (go(mid, 0, n, v, l, r)) {
			i = mid + 1;
			ans2 = mid;
		}
		else {
			j = mid - 1;
		}
	}

	cout << ans1 << " " << ans2 << "\n";

	if (ans1 == -1 || ans2 == -1) {
		cout << "0\n";
	}
	else {
		int ans = (ans2 - ans1);
		cout << ans << "\n";
	}

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