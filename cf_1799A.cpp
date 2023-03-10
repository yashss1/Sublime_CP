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
  set<int> st;
  vector<int> v, vv(m);
  for(int i = 1; i <= n; i++) {
  	v.push_back(i);
  	st.insert(i);
  }
  reverse(all(v));

  int k = 1;
  map<int, int> mp;
  int temp = 0;
  for(int i = 0; i < m; i++) {
  	cin >> vv[i];
  	if(!st.empty() && st.find(vv[i]) == st.end()) {
  		// cout << vv[i] << "\n";
  		st.erase(st.find(v[temp]));
  		st.insert(vv[i]);
  		v.push_back(vv[i]);
  		mp[v[temp]] = k;
  		temp++;
  	}
  	k++;

  	// cout << temp << "||\n";

  	// pVec(v);
  }


  for(int i = 1; i <= n; i++) {
  	if(mp[i] == 0) {
  		cout << "-1 ";
  	}
  	else {
  		cout << mp[i] << " ";
  	}
  }

  cout << '\n';

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