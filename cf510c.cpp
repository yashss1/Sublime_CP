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

vector<vector<int>> adj;
vector<int> vis(30, 0);

vector<char> ans;
bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:adj[i]){
			// cout << char(i + 'a' - 1) << " " << it << '\n';
			indeg[it]++;
		}
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i]){
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for(auto &v:adj[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return ans.size() == n;
}

void yash()
{
  int n;
  cin >> n; 
  vector<string> v(n);
  adj.resize(28);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  for(int i = 1; i < n; i++) {
  	string a = v[i - 1], b = v[i];
  	int p = 0, q = 0, idx = -1;
  	if(a == b) continue;
  	while(p < a.size() && q < b.size()) {
  		if(a[p] != b[q]){
  			adj[a[p] - 'a' + 1].push_back(b[q] - 'a' + 1);
  			idx = 1;
  			break;
  		}
  		p++, q++;
  	}
  	if(b.size() < a.size() && idx == -1) {
  		cout << "Impossible\n";
  		return;	
  	}
  }

  // for(int i = 0; i < 26; i++) {
  // 	cout << char(i + 'a') << " -> ";
  // 	pVec(adj[i]);
  // 	if(adj[i].size() > 0){
  // 		if(vis[i] == 0) {
  // 			dfs(i);
  // 		}
  // 	}
  // }
  // reverse(ans.begin(), ans.end());
  // map<char, int> mp;
  // for(auto it: ans) {
  // 	mp[it]++;
  // }

  // int k = 0;
  // string res = "";
  // for(char c = 'a'; c <= 'z'; c++) {
  // 	if(mp[c]) {
  		
  // 	}else{
  // 		res.push_back(c);
  // 	}
  // 	while(ans[k] <= c && k < ans.size()) {
  // 		res.push_back(ans[k]);
  // 		k++;
  // 	}
  // }

  // pVec(ans);
  // cout << res << '\n';

 	if (toposort(26)) {
		for (int x : ans) {
			char ch = (char) (x - 1 + 'a');
			cout << ch;
		}
		cout << '\n';

	} else {
		cout << "Impossible\n";
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