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
  int n;
  cin >> n; 
  int l = 1, r = 1e9;
  int x = 0;

  while(l <= r) {
  	int mid = (l + r) / 2;
  	int t = mid * (2 * mid - 1);
  	if(t <= n) {
  		x = mid;
  		l = mid + 1;
  	}else {
  		r = mid - 1;
  	}
  }

  int sum = (x * (2 * x - 1));
  int alice = 0, bob = 0;

  int a, b;
  if(x % 2 == 0) {
    alice += (n - sum);
  	a = x / 2;
  	b = x / 2;
  }
  else {
    bob += (n - sum);
  	a = (x / 2) + 1;
  	b = (x / 2);
  }


  alice += (4 * (a * a) - (3 * a));
  bob += ((4 * b * b) + b);

  cout << alice << " " << bob << '\n';
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