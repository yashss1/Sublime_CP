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

void yash()
{
  int n, m;
  cin >> n >> m; 
  vector<int> a(n), b(m), c(m);

  for(int i = 0; i < n; i++) {
  	cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
  	cin >> b[i];
  }
  for(int i = 0; i < m; i++) {
  	cin >> c[i];
  }

  int curr = 0, mn = INT_MAX, idx = 0;
  for(int i = 0; i < m; i++) {
  	int temp = a[0] / b[i];
	if (a[0] % b[i]) {
		temp++;
	}
	temp *= c[i];
	if (temp < mn) {
		mn = temp;
		idx = i;
	}
  }

  int ans = 0;
  for(int i = 1; i < n; i++) {
	int temp = a[i] / b[idx];
	if (a[i] % b[idx]) {
		temp++;
	}
	temp *= c[idx];
	ans += temp;
  }

  cout << ans + mn << "\n";
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
