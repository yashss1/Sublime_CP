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

// https://cp-algorithms.com/graph/bellman_ford.html#implementation_1
int n, m;
vector<int> d;
vector<pair<pair<int, int>, int>> e;
const int INF = 1e9;

void BellmanFord()
{
    vector<int> d (n + 1, INF);
    d[1] = 0;
    vector<int> p (n + 1, - 1);
    int x;
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].first.second] > d[e[j].first.first] + e[j].second)
            {
                d[e[j].first.second] = d[e[j].first.first] + e[j].second;
                p[e[j].first.second] = e[j].first.first;
                x = e[j].first.second;
            }
    }

    if (x == -1){
    	cout << "NO\n"; // no negative cycle
    }
    else
    {
        int y = x;
        for (int i=0; i < n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "YES\n";
        for (int i=0; i< (int)path.size(); ++i)
            cout << path[i] << ' ';
        cout << '\n';
    }
}

void yash()
{
  cin >> n >> m; 

  for(int i = 0; i < m; i++){
  	int u, v, w;
  	cin >> u >> v >> w;

  	e.push_back({{u, v}, w});
  }

  BellmanFord();

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