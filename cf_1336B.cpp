//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

unsigned long long solve(vector<int> a, vector<int> b, vector<int> c) {
	int n = a.size();
	int m = b.size();
	int q = c.size();

	unsigned long long ans = 1e19;
	for(int i = 0; i < n; i++) {
		int l = 0, r = m - 1;
		int idx = m - 1;
		int want = a[i];
		vector<vector<int>> temp;

		while(l <= r) {
			int mid = (l + r) / 2;
			if(b[mid] > want) {
				idx = mid;
				r = mid - 1;
			}else {
				l = mid + 1;
			}
		}

		l = 0, r = q - 1;
		want = b[idx];
		int idx1 = q - 1;

		while(l <= r) {
			int mid = (l + r) / 2;
			if(c[mid] > want) {
				idx1 = mid;
				r = mid - 1;
			}else {
				l = mid + 1;
			}
		}

		temp.push_back({a[i], want, c[idx1]});
		if(idx1 > 0) {
			temp.push_back({a[i], want, c[idx1 - 1]});
		}

		if(idx > 0) {
			l = 0, r = q - 1;
			want = b[idx - 1];
			int idx1 = q - 1;
			while(l <= r) {
				int mid = (l + r) / 2;
				if(c[mid] > want) {
					idx1 = mid;
					r = mid - 1;
				}else {
					l = mid + 1;
				}
			}

			temp.push_back({a[i], want, c[idx1]});
			if(idx1 > 0) {
				temp.push_back({a[i], want, c[idx1 - 1]});
			}
		}


		for(auto it: temp) {
			vector<int> t = it;
			// pVec(t);

			unsigned long long curr = ((t[0] - t[1]) * (t[0] - t[1])) + ((t[1] - t[2]) * (t[1] - t[2])) + ((t[0] - t[2]) * (t[0] - t[2]));
			ans = min(ans, (unsigned long long)curr);
		}
	}

	return ans;
}

void yash()
{
  int r, g, b;
  cin >> r >> g >> b; 
  vector<int> x(r), y(g), z(b);

  for(int i = 0; i < r; i++) {
  	cin >> x[i];
  } 
  for(int i = 0; i < g; i++) {
  	cin >> y[i];
  } 
  for(int i = 0; i < b; i++) {
  	cin >> z[i];
  } 

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(z.begin(), z.end());

  unsigned long long ans = 1e19;
  // xyz
  ans = min(ans, (unsigned long long)solve(x, y, z));
  // xzy
  ans = min(ans, (unsigned long long)solve(x, z, y));
  // yxz
  ans = min(ans, (unsigned long long)solve(y, x, z));
  // yzx
  ans = min(ans, (unsigned long long)solve(y, z, x));
  // zxy
  ans = min(ans, (unsigned long long)solve(z, x, y));
  // zyx
  ans = min(ans, (unsigned long long)solve(z, y, x));

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