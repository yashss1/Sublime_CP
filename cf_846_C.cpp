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
  int n, m;
  cin >> n >> m;
  vector<int> v(n), c(m);
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	mp[v[i]]++; 
  } 
  for(int j = 0; j < m; j++) {
  	cin >> c[j];
  }
  sort(all(c), greater<int>());

  priority_queue<int> pq;
  for(auto it: mp) {
  	pq.push(it.second);
  }

  	
  int ans = 0;
  // while(!pq.empty()) {
  	for(int i = 0; i < m; i++){
  		int t = c[i];

  		int t1 = pq.top();
  		pq.pop();

  		if(t >= t1) {
  			ans += t1;
  		}else{
  			ans += t;
  			t1 -= t;
  			pq.push(t1);
  	 	}
    }
  // }

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