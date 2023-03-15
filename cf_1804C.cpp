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
  int n, x, p;
  cin >> n >> x >> p;

  int min_to_zero = (n - x);
  min_to_zero %= n;
  // cout << min_to_zero << "\n";

  int till = min(n * (int)log2(n), p);
  for(int i = 1; i <= till; i++) {
  	int t = (i * (i + 1)) / 2;
  	if((t % n) == min_to_zero) {
  		cout << "Yes\n";
  		return;
  	}
  }

  cout << "No\n";
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