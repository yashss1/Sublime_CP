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
  int n;
  cin >> n; 
  vector<int> v(n);
  set<int> st;
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	st.insert(v[i]);
  	mp[v[i]]++;
  }

  v.clear();
  for(auto it: st) {
  	v.push_back(it);
  }

  n = v.size();

  for(int i = 0; i < n; i++) {
  	if(mp[v[i]] % 2) {
  		cout << "Marichka\n";
  		return;
  	}
  }

  cout << "Zenyk\n";
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