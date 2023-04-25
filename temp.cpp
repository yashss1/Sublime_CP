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
  int p, q, l, r;
  cin >> p >> q >> l >> r; 
  vector<pair<int, int>> a, b;
  for(int i = 0; i < p; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }

  for(int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    b.push_back({x, y});
  }


  int ans = 0;
  for(int t = l; t <= r; t++) {
    // is t possible? 
    int flag = 0;
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) {
            if((b[j].first + t <= a[i].first && b[j].second + t >= a[i].first) ||
                        (b[j].first + t >= a[i].first && b[j].first + t <= a[i].second)) {
                flag = 1;
            }
        }
    }

    ans += flag;
  } 

  cout << ans << '\n';
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