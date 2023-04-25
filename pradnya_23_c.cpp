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

int n, h, k;
vector<int> d(N), t(N);

int solve(int mid) {
	int curr = 0;
	for(int i = 0; i < n; i++) {
		if(k * (i + 1) > mid) {
			break;
		}
		cout << i << " " << curr << ' ';
		int tt = ((min(i + 1, mid) / t[i]) * d[i]);
		cout << tt << '\n';
		curr += tt;
	}
	if(curr > h) {
		return 0;
	}
	return 1;
}

void yash()
{
  cin >> n >> h >> k; 
  for(int i = 0; i < n; i++) {
  	cin >> d[i];
  }
  for(int i = 0; i < n; i++) {
  	cin >> t[i];
  }

  cout << solve(6) << '\n';
  return;
  int l = 0, r = (k * n);
  int ans = 0;
  while(l <= r) {
  	int mid = (l + r) / 2;
  	if(solve(mid)) {
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