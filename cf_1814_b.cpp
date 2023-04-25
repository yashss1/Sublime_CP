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
const int N = 1e2 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/// To find pattern to reach to 0, n -> 
// Output : 1 2 3 3 4 4 5 5 5 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 9 10 10 10 10 10
int n;
int dp[N][N];
int go(int idx, int sz) {
  if(idx == n) {
    return 0;
  }
  if(sz > n || idx > n) {
    return 10000;
  }

  int &ans = dp[idx][sz];
  if(ans != -1) {
    return ans;
  }
  int c1 = 1 + go(idx, sz + 1);
  int c2 = 1 + go(idx + sz, sz);

  return ans = min({c1, c2});
}

// trace function gives maz last jump size to go to 0, n;
void trace(int idx, int sz) {
  if(idx == n) {
    cout << sz << '\n';
    return;
  }
  if(sz > n || idx > n) {
    return;
  }

  int ans = dp[idx][sz];

  int c1 = 1 + go(idx, sz + 1);
  if(ans == c1) {
    trace(idx, sz + 1);
    return;
  }
  int c2 = 1 + go(idx + sz, sz);
  if(ans == c2) {
    trace(idx + sz, sz);
    return;
  }

  assert(false);
}

void yash()
{
  int a, b;
  cin >> a >> b; 

  // // go to 0, mn
  // int mn = min(a, b);
  // int ans = (mn + 1) / 2;

  // int max_jump = 3; // kr calulcate using trace function (find pattern)
  // ans += (max(a, b) / (max_jump));
  // int remain = (max(a, b) % (max_jump) + 1) / 2;

  // cout << ans + remain << "\n";

  int ans = a + b;
  for(int i = 1; i <= 1e5; i++) {
    ans = min(ans, i - 1 + (a / i + (a % i == 0 ? 0 : 1)) + (b / i + (b % i == 0 ? 0 : 1)));
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