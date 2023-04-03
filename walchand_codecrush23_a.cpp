#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
https://www.hackerrank.com/codecrush-expert-2k23
*/

void solve()
{
  int a, b;
  cin >> a >> b;
  if(a + b < 3) {
  	cout << "1\n";
  	return;
  }
  if(a + b <= 10) {
  	cout << "2\n";
  	return;
  }
  if(a + b <= 60) {
  	cout << "3\n";
  	return;
  }
  if(1) {
  	cout << "4\n";
  	return;
  }
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  test
  solve();
  return 0;
}