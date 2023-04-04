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
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d; 
  a = min(a, n - a + 1);
  d = min(d, n - d + 1);
  b = min(b, n - b + 1);
  c = min(c, n - c + 1);

  int bx1 = min(c, d);
  int bx2 = min(b, a);
  // cout << bx2 <<" " << bx1 << "\n";
  cout << abs(bx2 - bx1) << '\n';
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