// codedrift-jan-2-0-d.cpp

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

int mod_add(int a, int b, int m) {a = a % m; b = b % m; 
return (((a + b) % m) + m) % m;}

string l, r;
int n;

int dp[2][2][2][10][10][16][20];
// states: edgeTop, edgeBottom, first_non_zero_taken, mx, mn, xor, idx;

int go(int idx, int edgeBottom, int edgeTop, int mx, int mn, int xr, int first_non_zero_taken){
  if(idx==n){
    double avg = (mn+mx)/2;
    double xorSum = xr;

    if(xorSum>avg){
      return 1;
    }
    return 0;
  }

  int &ans = dp[edgeTop][edgeBottom][first_non_zero_taken][mx][mn][xr][idx];
  if(ans!=-1){
    return ans;
  }

   ans = 0;
  for (int i = 0; i < 10; i++) {
    if (edgeBottom && i < l[idx] - '0')continue;
    if (edgeTop && i > r[idx] - '0')continue;

    ans = mod_add(ans, (go(idx + 1, edgeBottom && (i == l[idx] - '0'), edgeTop && (i == r[idx] - '0'), max(mx, i), (first_non_zero_taken==0 && i!=0)? i : min(mn, i), xr^i, (first_non_zero_taken|(i!=0)))), MOD);
  } 
  return ans;
}

void yash()
{
  memset(dp, -1, sizeof(dp));
  cin >> l >> r;
  reverse(l.begin(), l.end());
  while (l.size() < r.size()) {
    l += "0";
  }
  reverse(l.begin(), l.end());
  n = r.size();

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (i < l[0] - '0')continue;
    if (i > r[0] - '0')continue;

    ans += (go(1, (i == l[0] - '0'), i == r[0] - '0', i, i, i, (i==0)?0:1));
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