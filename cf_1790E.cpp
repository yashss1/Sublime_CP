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
  if(n % 2 == 1) {
  	cout << "-1\n";
  	return;
  }

  n /= 2;

  int a = 0, b = 0;
  int flag = 0;

  for(int i = 15; i >= 0; i--) {
  	if(n & (1 << i)) {
  		a += (1 << i);
      flag = 1;
  	}
    if(flag == 1) {
      b += (1 << i);  
    }
  }

  cout << a << " " << b << " | " << (b & a) << '\n';

  if(a == b) {
  	cout << "-1\n";
  	return;
  }

  // int t = (a ^ b);
  // int t1 = (a + b) / 2;
  // if(t != t1) {
  //   cout << t << " " << t1 << '\n';
  //   cout << "NOT\n";
  //   return;
  // }

  cout << a << " " << b << '\n';
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