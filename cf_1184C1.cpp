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
    if(p1.first != p2.first)return p1.first < p2.first;
    else {
      return p1.second < p2.second;
    }
}

void yash()
{
  int n;
  cin >> n; 
  vector<pair<int, int>> v;
  for(int i = 0; i < 4 * n + 1; i++) {
  	int x, y;
  	cin >> x >> y;
  	v.push_back({x, y});
  }

  // for(int i = 0; i < 51; i++) {
  	// for(int j = 0; j < 51; j++) {
  		// i, j is bottom left corner of this square
  		// i, j -> i + n, j + n

  		for(int p = 0; p <= 50; p++) {
  			for(int q = 0; q <= 50; q++) {
  				for(int sz = 1; sz <= 50; sz++) {
  					vector<int> vis(4 * n + 4, 0);
  					int curr = 0;
  					for(int pq = 0; pq < 4 * n + 1; pq++) {
  						if(v[pq].first == p || v[pq].first == p + sz || v[pq].second == q || v[pq].second == q + sz) {
  							// cout << sz << " -> ";
  							// cout << v[pq].first << " " << v[pq].second << '\n';
  							vis[pq] = 1;
  							curr++;
  						}
  					}

  					if(curr == 4 * n && sz >= n) {
  						for(int pq = 0; pq < 4 * n + 1; pq++) {
  							if(vis[pq] == 0) {
  								cout << v[pq].first << " " << v[pq].second << '\n';
  								return;
  							}
  						}
  					}
  				}
  			}
  		}
  	// }
  // }
  cout << "-1\n";
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