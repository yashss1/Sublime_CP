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

int n, k;
vector<pair<int, int>> v(N);

void yash()
{
  cin >> n >> k;  
  v.assign(n, {0, 0});
  for(int i = 0; i < n; i++) {
  	int x; cin >> x;
  	v[i].first = x;
  }
  for(int i = 0; i < n; i++) {
  	int x; cin >> x;
  	v[i].second = x;
  }

  int ans = 0, prev = 0, taken = 0;
  multiset<int> st;
  for(int i = 0; i < n; i++) {
  	int l = v[i].first, r = v[i].second;
  	ans += 2;
  	ans += (r - l);
  	ans += (l - prev);
  	prev = r;
  }

  // for(auto it: v) {
  // 	cout << it.first << " " << it.second << '\n';
  // }

  ans = INT_MAX;
  for(int i = 0; i < n; i++) {
  	int len = (v[i].second - v[i].first);
  	if(taken + len + 1 < k) {
  		taken += len + 1;
  		st.insert(len + 1);
  		continue;
  	}

  	int temp = (k == taken) ? (0) : 2;
  	int this_cost = v[i].first + temp - taken + (2 * (st.size()) + k - 1);

  	ans = min(ans, this_cost);

  	while (!st.empty()) {
  		if((taken + len + 1 - (*st.begin())) < k) break;
        taken -= (*st.begin());
        st.erase(st.begin());
      
        temp = (k == taken) ? (0) : 2;
        this_cost = v[i].first + temp - taken + (2 * (st.size()) + k - 1);
        ans = min(ans, this_cost);
    }
  	taken += (len + 1);
  	st.insert(len + 1);
  }

  if(ans == INT_MAX) {
  	cout << "-1\n";
  	return;
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