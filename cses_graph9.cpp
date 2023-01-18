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

//https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html#implementation
const int INF = 1e18;
vector<vector<int>> d;
int n;

// N^3
void floydWarshal() {
    for (int k = 1; k <= n; ++k) {
    	for (int i = 1; i <= n; ++i) {
    	    for (int j = 1; j <= n; ++j) {
    	        // if (d[i][k] < INF && d[k][j] < INF)
    	            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
    	    }
    	}
	}
}

void yash()
{
  int m, q;
  cin >> n >> m >> q;  
  d.assign(n + 1, vector<int>(n + 1, INF));
  for(int i = 1; i <= n; i++){
    d[i][i] = 0; // Important
  }

  for(int i = 0; i < m; i++){
  	int u, v, w;
  	cin >> u >> v >> w;

  	d[u][v] = min(d[u][v], w);
  	d[v][u] = min(d[v][u], w);
  }

  floydWarshal();

  while(q--) {
  	int a, b;
  	cin >> a >> b;

  	int t = d[a][b];
  	if(t == INF) {
  		cout << "-1\n";
  		continue;
  	}

  	cout << t << '\n';
  }

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