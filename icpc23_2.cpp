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
  map<string, int> mp;
  set<string> st;
  for(int i = 0; i < n; i++) {
  	string s;
  	getline(cin, s);

  	mp[s]++;
  	if(i < 10) continue;
  	st.insert(s);
  }

  vector<string> v;
  for(auto it: st) {
  	if(it.size() == 0) continue;
  	cout << it << '\n';
  	v.push_back(it);
  }

  cout << v.size() << '\n';
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