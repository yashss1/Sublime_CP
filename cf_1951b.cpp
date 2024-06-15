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

	// int mx = 0;
	// for (int i = 0; i < k; i++) {
	// 	mx = max(mx, v[i]);
	// }

	// vector<int> ans(n, 0);
	// for (int i = 0; i < n; i++) {
	// 	if (v[i] < v[k - 1]) {
	// 		ans[i] = 1;
	// 	}
	// 	else {
	// 		ans[i] = 0;
	// 	}
	// }

	int mx = v[k - 1], idx = k - 1;
	int taken = 0;
	for (int i = 0; i < k; i++) {
		if (v[i] > v[k - 1]) {
			if (mx < v[i]) {
				mx = v[i];
				idx = i;
				taken++;
				break;
			}
		}
	}
	// cout << v[idx] << " " << v[k - 1] << '\n';
	swap(v[idx], v[k - 1]);
	int wins = 0;
	int mx2 = 0;
	for (int i = 0; i < idx; i++) {
		mx2 = max(mx2, v[i]);
	}
	if (idx > 0) {
		if (mx2 < v[idx]) {
			wins++;
		}
		else {
			cout << "0\n";
			return;
		}
	}
	for (int i = max(idx + 1, 0ll); i < n; i++) {
		if (v[i] < v[idx]) {
			wins++;
		}
		else {
			if (taken == 1) {
				break;
			}
			else {
				i++;
			}
		}
	}
	cout << max(idx, wins) << '\n';
	return;
	// pVec(ans);

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