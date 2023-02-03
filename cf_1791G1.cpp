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
  int n, c;
  cin >> n >> c; 
  vector<pair<int,int>> v;
  for(int i = 0; i < n; i++) {
  	int a;
  	cin >> a;
  	a += i + 1;
  	v.push_back({a, i});
  }

  sort(v.begin(), v.end());


  int ans = 0;
  for(int i = 0; i < n; i++) {
  	if(v[i].first <= c) {
  		c -= v[i].first;
  		ans++;
  	}
  }
  cout << ans << '\n';

  // cout << c << '\n';
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