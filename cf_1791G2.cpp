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
  int n, c;
  cin >> n >> c; 
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  //{val, idx, 0 for straight else 1 for reverse direction}

  priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq, pqq;
  for(int i = 0; i < n; i++) {
  	pq.push({v[i] + i + 1, {i, 0}});
  	pq.push({v[i] + (n - i), {i, 1}});
  	pqq.push({v[i] + i + 1, {i, 0}});
  	pqq.push({v[i] + (n - i), {i, 1}});
  }

  vector<int> vis(n, 0);
  vector<pair<int, pair<int, int>>> vv;

  int ans = 0;
  int t = 2;

  while(!pqq.empty()) {
  	pair<int, pair<int, int>> temp = pqq.top();
  	pqq.pop();

  	if(temp.second.second == 0 && t--) {
  		vv.push_back(temp);
  		// vis[temp.second.first] = 1;
  		// cout << temp.second.first << '\n';
  		// c -= temp.first;
  		// if(c < 0) {
  			// cout << "0\n";
  			// return;
  		// }
  		// ans++;
   		// break;
  	}
  }

  for(int i = 0; i < vv.size(); i++) {
  	// cout << vv[i].first << "\n";
  	int curr = 0, cc = c;
  	vector<int> taken;

  	vis[vv[i].second.first] = 1;
  	taken.push_back(vv[i].second.first);
  	cc -= vv[i].first;
  	if(cc < 0) {
  		continue;
  	}
  	curr++;
  	// priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pqq;
  	// pqq = pq;

  	vector<pair<int, pair<int, int>>> taken2;
  	while(!pq.empty()) {
  		pair<int, pair<int, int>> temp = pq.top();
  		taken2.push_back(temp);
  		pq.pop();

  		if(vis[temp.second.first] == 1) {
  			continue;
  		}	

  		vis[temp.second.first] = 1;
  		taken.push_back(temp.second.first);
  		cc -= temp.first;

  		if(cc < 0) {
  			goto end;
  		}
  		curr++;
  	}

  	end:
  	ans = max(ans, curr);


  	for(auto it: taken) {
  		vis[it] = 0;
  	}
  	for(auto it: taken2) {
  		pq.push(it);
  	}

  }

  cout << ans << '\n';

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