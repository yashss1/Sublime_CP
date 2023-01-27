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
  vector<vector<string>> v = {{"this", "is", "a", "page", "this"}, {"this", "is", "another", "page"}};

  // subtask A: print all i where a given word is present
  // subtask B: print the number of times the word has occured in entire v
  // map<string, set<int>> mp;
  // this -> [1, 2]
  // another -> [2]
  // this -> 3

  map<string, int> mp1;
  map<string, vector<int>> mp;

  for(int i = 0; i < v.size(); i++) {
  	for(int j = 0; j < v[i].size(); j++) {
  		mp[v[i][j]].push_back(i + 1);
  	}
  }

  for(auto &it: mp) {
  	sort(all(it.second));
  }

  string s = "this";

  int curr = mp[s].size();
  
  cout << mp[s][0] << ' ';
  for(int i = 1; i < mp[s].size(); i++) {
  	if(mp[s][i - 1] != mp[s][i]) {
  		cout << mp[s][i] << ' ';
  	}
  }
  cout << '\n';

  cout << curr << '\n';
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