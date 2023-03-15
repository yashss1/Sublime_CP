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
  int a, b;
  cin >> a >> b; 
  a = abs(a);
  b = abs(b);
  int t = min(a, b);
  int ans = t * 2;

  a -= t;
  b -= t;
  a = max(a, b);
  // cout << a << " " << b  << "\n";

  if(a == 0) {
  	cout << ans << '\n';
  	return;
  }

  t = a - 1;
  t *= 2;
  t++;
  // int t1 = a - (a / 2);
  // cout << ans << " " << t << " " << t1 << "\n";
  ans += t; 
 
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