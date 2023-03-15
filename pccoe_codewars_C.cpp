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
  int d, s1, s2, m, x, n, y;
  cin >> d >> s1 >> s2 >> m >> n >> x >> y;
  double t1 = m * x;
  double t2 = n * y;

  double a = d / (float)(s1);
  double b = d / (float)(s2);

  a += t1;
  b += t2;

  if(a == b) {
  	cout << "The perfect date\n";
  	return;
  }

  if(a < b) {
  	cout << "Darshan\n";
  	return;
  }

  cout << "Crush\n";

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