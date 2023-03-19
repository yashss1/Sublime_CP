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
int n;
vector<pair<int, int>> v[2]; // node, {time_min, whose_min}
int ans = 0;

void bfs(int node, int type, int which_tom) {
	queue<pair<int, int>> q;
	q.push({node, 0});
	vector<int> vis(n + 1, 0);
	vis[node] = 1;
	while(!q.empty()) {
		pair<int, int> curr = q.front();
		if(v[type][curr.first ].first > curr.second) {
			v[type][curr.first ].first = curr.second;
			v[type][curr.first ].second = which_tom;
		}
		q.pop();
		if(type == 0) {
			if(v[1][curr.first].first <= v[0][curr.first].first) {
				ans++;
				continue;
			}
		}

		for(auto it: adj[curr.first]) {
			if(!vis[it]) {
				vis[it] = 1;
				q.push({it, curr.second + 1});
			}
		}
	}
}

void yash()
{
  int m;
  cin >> n >> m;
  v[0].resize(n + 1);
  v[1].resize(n + 1);

  for(int i = 0; i < n - 1; i++) {
  	int x, y;
  	cin >> x >> y;
  	adj[x].push_back(y);
  	adj[y].push_back(x);
  }

  vector<int> leaf;
  for(int i = 1; i <= n; i++) {
  	v[0][i].first = INT_MAX;
  	v[0][i].second = -1;
  	v[1][i].first = INT_MAX;
  	v[1][i].second = -1;
  	if(adj[i].size() == 1) {
  		leaf.push_back(i);
  	}
  }

  int k = 0;
  for(auto it : leaf) {
  	bfs(it, 1, k);
  	k++;
  }
  bfs(m, 0, 0);

  // for(int i = 1; i <= n; i++) {
  // 	cout << v[1][i].first << " " << v[0][i].first << ' ' << v[1][i].second << "\n";
  // }

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

// 1 3 6 5 -> 2nd larget k = 2
// 1 2 3 4 5 6 7 8 9 10
// 1 0 1 0 1 1 0 0 0 0

// k = 0
// 1
// 2


