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

bool cmp(pair<int,int>&p1, pair<int,int>&p2){
    if(p1.second!=p2.second)return p1.second<p2.second;
    else{
      return p1.first>p2.first;
    }
}

void yash()
{
  int n, r, s;
  cin >> n >> r >> s; 
  vector<pair<int, int>> v;
  int sum = 0;
  for(int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      if(a > r) {
          assert(false);
      }
      v.push_back({r - a, b});
      sum += a;
  }

  if(sum >= s) {
      cout << "0\n";
      return;
  }

  sort(all(v), cmp);
  // for(auto it: v) {
  //     cout << it.first << " " << it.second << '\n';
  // }

  int want = s - sum;
  int ans = 0;
  int i = 0;
  while(want > 0 && i < n) {
      if(want - (v[i].first) >= 0) {
          ans += (v[i].first * v[i].second);
          want -= (v[i].first);
      }
      else {
          ans += (want * v[i].second);
          want = 0;
      }
      i++;
  }

  if(want > 0) {
      cout << "-1\n";
      return;
  }
  cout << ans << '\n';

}

signed main()
{
  // init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // test
  yash();
  return 0;
}