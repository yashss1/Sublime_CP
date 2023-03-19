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

// https://codeforces.com/gym/433004/problem/A
void yash()
{
  string s, t, p;
  cin >> s >> t >> p; 
  map<char, int> ss, tt, pp;
  for(int i = 0; i < s.size(); i++) {
  	ss[s[i]]++;
  }
  for(int i = 0; i < t.size(); i++) {
  	tt[t[i]]++;
  }
  for(int i = 0; i < p.size(); i++) {
  	pp[p[i]]++;
  }

  // for(auto it: tt) {
  // 	if(it.second <= ss[it.first] + pp[it.first]) {

  // 	}
  // 	else {
  // 		cout << "NO\n";
  // 		return;
  // 	}
  // }

  int i = 0, j = 0;
  while(i < s.size() && j < t.size()) {
  	if(s[i] == t[j]) {
  		i++, j++;
  	}
  	else {
  		if(pp[t[j]] == 0) {
  			cout << "NO\n";
  			return;
  		}
  		pp[t[j]]--;
  		j++;
  	}
  }

  // cout << i << " " << j << "\n";
  for(; j < t.size(); j++) {
  	if(pp[t[j]] == 0) {
  		cout << "NO\n";
  		return;
  	}
  	pp[t[j]]--;
  }

  if(i < s.size()) {
  	cout << "NO\n";
  	return;
  }

  cout << "YES\n";

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