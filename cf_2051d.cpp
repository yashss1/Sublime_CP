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
	int n, x, y;
	cin >> n >> x >> y; 
	vector<int> v(n);
	int sum = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());
	// pVec(v);
	// cout << sum << "\n";

	for(int i = 0; i < n; i++) {
		int currSum = sum - v[i];
		int mxMinus = max(0ll, currSum - x), mnMinus = max(0ll, currSum - y);

		int idx1 = -1, idx2 = -1;

		if(mxMinus >= 0) {
			int l = i + 1, r = n - 1;
			while(l <= r) {
				int mid = (l + r) / 2;

				if(v[mid] <= mxMinus) {
					idx2 = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}

			}
		}
		if(mnMinus >= 0) {
			int l = i + 1, r = n - 1;
			while(l <= r) {
				int mid = (l + r) / 2;

				if(v[mid] >= mnMinus) {
					idx1 = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}

			}
		}

		// cout << i << " " << currSum << " -> " << mnMinus << " " << mxMinus << " | " << idx1 << " " << idx2 << '\n';
		if(idx1 <= idx2 && mnMinus >= 0 && mxMinus >= 0 && idx1 != -1 && idx2 != -1) {
			ans += (idx2 - idx1 + 1);
		}
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