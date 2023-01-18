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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m;
vector<int> adj[N];
vector<int> vis(N, 0);
vector<int> present_in_stack(N, 0), parent(N, 0);
stack<int> st;

// cycle detection in directed graph
bool dfs(int node) {
 vis[node] = 1;
 present_in_stack[node] = 1;
 st.push(node);

 for(auto it : adj[node]) {
 	if(vis[it] == 0) {
 		if(dfs(it)) {
 			return true;
 		}
 	}

 	if(present_in_stack[it]) {
 		st.push(it);
 		return true;
 	}
 }

 st.pop();
 present_in_stack[node] = 0;
 return false;
}

void yash()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for(int i = 1; i <= n; i++) {
  	if(vis[i] == 0){
  		if(dfs(i)){
			break;
  		}
  	}
  }

  vector<int> ans;
  map<int, int> already_taken;
  while(!st.empty()){
  	ans.push_back(st.top());
  	if(already_taken[st.top()] == 1){
  		break;
  	}
  	already_taken[st.top()] = 1;
   	st.pop();
  }

  if(ans.size() == 0) {
  	cout << "IMPOSSIBLE\n";
  	return;
  }

  reverse(all(ans));
  cout << ans.size() << '\n';
  pVec(ans);
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