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
  string s;
  cin >> s;
   if(s[0] == '0') {
  	cout << "0\n";
  	return;
  }

  int ans = 1, flag = 0;
  for(int i = 0; i < s.size(); i++) {
  	if(i == 0 && s[i] == '?') {
  		flag = 1;
  		ans *= 9;
  	}
  	else if(s[i] == '?') {
  		flag = 1;
  		ans *= 10;
  	}
  }

  if(flag == 0) {
  	cout << "1\n";return;
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