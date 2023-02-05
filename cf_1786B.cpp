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
  int n, w, h;
  cin >> n >> w >> h; 
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) {
  	cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
  	cin >> b[i];
  }

  // if(a[0] < b[0]) {
  // 	for(int i = 0; i < n; i++) {
  // 		if(a[i] > b[i]) {
  // 			cout << "NO\n";
  // 			return;
  // 		}
  // 	}
  // }
  // if(b[0] < a[0]) {
  // 	for(int i = 0; i < n; i++) {
  // 		if(b[i] > a[i]) {
  // 			cout << "NO\n";
  // 			return;
  // 		}
  // 	}
  // }

  int max_allowed = (a[0] + w  - (b[0] + h));
  int min_want = (a[0] - w  - (b[0] - h));

  for(int i = 1; i < n; i++) {
  	int max_allowed_temp = (a[i] + w  - (b[i] + h));
  	int min_want_temp = (a[i] - w  - (b[i] - h));

  	if(max_allowed_temp < min_want || min_want_temp > max_allowed) {
  		cout << "NO\n";
  		return;
  	}
  	
  	min_want = max(min_want, min_want_temp);
  	max_allowed = min(max_allowed, max_allowed_temp);
  }

  cout << "YES\n";
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