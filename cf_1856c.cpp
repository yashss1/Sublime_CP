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

bool solve(int n, vector<int> &v, int k, int mid) {
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		int temp = mid;
		int curr = 0;
		int fl = 0;

		// cout << i << " -> ";
		for(int j = i; j < n; j++) {
			if(temp <= v[j]) {
				fl = 1;
				break;
			}
			// cout << v[j] << " " << temp << "\n";

			curr += (temp - v[j]);
			temp--;
		}
		// cout << curr << "\n";
		// cout << '\n';

		if(fl == 1) ans = min(ans, curr);
	}

	// cout << mid << " " << ans << '\n';
	if(ans <= k) {
		return true;
	}
	return false;

}

void yash()
{
	int n, k;
	cin >> n >> k; 
	vector<int> v(n);
	int mx = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	// cout << solve(n, v, k, 7) << "\n";
	// return;

	int l = mx, r = 1e9;
	int ans = mx;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(solve(n, v, k, mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
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


