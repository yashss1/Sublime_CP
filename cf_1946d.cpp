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
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	int OR = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		OR |= v[i];
	}

	if (OR <= x) {
		cout << n << "\n";
		return;
	}

	vector<vector<int>> pref(31, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		int mx = i;
		int XOR = v[i];
		for (int j = 0; j <= 30; j++) {
			if ((v[i] & (1 << j)) && (x & (1 << j))) {
				for (int k = i + 1; k < n; k++) {
					mx = max(mx, k);
				}
			}
			else if (v[i] & (1 << j)) {
				for (int k = i + 1; k < n; k++) {
					mx = max(mx, k);
				}
			}
			else {
				break;
			}
		}
		for (int i = 0; i < n; i++) {

		}
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