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
  int n, m, k;
  cin >> n >> m >> k; 
  map<string, string> mp;
  map<string, int> vis;
  for(int i = 0; i < n; i++) {
  	string a, b;
  	cin >> a >> b;
  	vis[a] = 1;
  	mp[a] = b;
  }

  map<int, string> mp1;
  for(int i = 0; i < m; i++) {
  	int x;
  	cin >> x;
  	string a;
  	cin >> a;
  	mp1[x] = a;
  }

  int k1 = 0;
  for(auto it: mp1) {
  	if(k1 >= k) break;
  	if(vis[it.second] == 0) continue;
  	cout << k1 + 1 << " " << it.second << " " << mp[it.second] << '\n';
  	k1++;
  }
  cout << "\n";

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