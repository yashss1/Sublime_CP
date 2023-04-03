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

// https://icpc.codedrills.io/contests/icpc-amritapuri-2022-regional-round/problems/longest-strictly-increasing-sequence
/*
2
6
1 2 3 2 5 7
2
1 2
*/

void yash()
{
  int n;
  cin >> n; 
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int k = 1;
  for(int i = 0; i < n; i++) {
    if(v[i] - v[i - 1] > 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  pVec(v);
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