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
  string s;
  cin >> s;
  map<int, int> mp;
  for(auto it: s) {
  	mp[it]++;
  } 

  if(mp.size() == 1) {
  	cout << "-1\n";return;
  }

  if(mp.size() == 4) {
  	cout << "4\n";return;
  }

  if(mp.size() == 2) {
  	vector<int> res;
    for(auto i:mp){
    	res.pb(i.second);
    }
    if(res[0]==2){
    	cout<<"4\n";return;
    }
  	cout << "6\n";return;
  }

  cout << "4\n";

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