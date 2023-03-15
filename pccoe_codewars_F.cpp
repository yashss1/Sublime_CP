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

// https://www.hackerrank.com/contests/codewars-first-round/challenges/catching-jerry
vector<int> adj[N];

void yash()
{
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n - 1; i++) {
  	int x, y;
  	cin >> x >> y;
  	adj[x].push_back(y);
  	adj[y].push_back(x);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
  	if(adj[i].size() == 1) {
  		ans++;
  	}
  }
  cout << ans << "\n";

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