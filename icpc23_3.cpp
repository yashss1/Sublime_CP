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
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int p = 0, q = 0;
  for(int i = 0; i < n; i++) {
  	if(a[i] == '1') {
  		p+=1;
  	}
  	if(a[i] == '3') {
  		p+=4;
  	}
  	if(a[i] == '5') {
  		p+=6;
  	}
  	if(a[i] == '7') {
  		p+=9;
  	}
  }

  for(int i = 0; i < n; i++) {
  	if(b[i] == '1') {
  		q+=1;
  	}
  	if(b[i] == '3') {
  		q+=4;
  	}
  	if(b[i] == '5') {
  		q+=6;
  	}
  	if(b[i] == '7') {
  		q+=9;
  	}
  }

  int ans = p - q;
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