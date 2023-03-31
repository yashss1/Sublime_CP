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

/// IN PROGRESS

vector<int> parent, sizee, ranks;
multiset<int> sizes;
vector<int> adj[N];
int n, m;
vector<int> v(N), vis(N, 0);

void make_set(int v) {
	parent[v] = v;
	sizee[v] = 1;
	ranks[v] = 0;
	sizes.insert(1);

}
int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}


// Have to edit this merge function in many questions
void merge(int a, int b) {
	//merge a in b
	// sizes.erase(size[a]); // THis will remove all the elements of that value
	sizes.erase(sizes.find(sizee[a]));
	sizes.erase(sizes.find(sizee[b]));

	sizes.insert(sizee[a] + sizee[b]);
}

void union_sets_bySize(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sizee[a] < sizee[b])
			swap(a, b);
		parent[b] = a;
		merge(a, b);
		sizee[a] += sizee[b];
	}
}
	
vector<int> res;
void dfs(int node, int curr) {
	vis[node] = 1;
	res.push_back(node);
	vector<int> rem;
	for(auto it : adj[node]) {

		if(vis[it] == 1) continue;
		if(v[it] == 0) {
			res.push_back(it);
			continue;
		}

		if(curr <= v[it]) {
			dfs(it, curr + 1);
		}
		else {
			rem.push_back(it);
		}
	}
	for(int i = 0; i < rem.size(); i++) {
		if(vis[rem[i]] == 1) continue;
		if(curr <= v[rem[i]]) {
			dfs(rem[i], curr + 1);
		}
	}

}
void yash()
{
  cin >> n >> m; 
  sizes.clear();
  sizee.assign(n + 2, 0);
  parent.assign(n + 2, 0);
  ranks.assign(n + 2, 0);
  vis.assign(n + 2, 0);
  for(int i = 1; i <= n; i++) {
  	cin >> v[i];
  	adj[i].clear();
  }
  for (int i = 1; i <= n; i++) {
 	make_set(i);
  }

  for(int i = 0; i < m; i++) {
  	int u, v;
  	cin >> u >> v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) {
  	res.clear();
  	if(v[i] == 0) {
  		dfs(i, 0);
  		pVec(res);
  		for(int i = 1; i < res.size(); i++) {
  			union_sets_bySize(res[i - 1], res[i]);
  		}
  	}
  }

  map<int, int> mp;
  for(int i = 1; i <= n; i++) {
  	mp[find_set(i)]++;
  }

  if(mp.size() == 1) {
  	cout << "YES\n";
  	return;
  }
  cout << "NO\n";
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