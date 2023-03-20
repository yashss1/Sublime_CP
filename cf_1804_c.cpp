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
  string s;
  cin >> s;
  map<char, int> mp, mp1;
  for(int i = 0; i < n; i+=2) {
  	mp[s[i]]++;
  }

  for(int i = 1; i < n; i+=2) {
  	if(mp[s[i]]) {
  		cout << "NO\n";
  		return;
  	}
  	// mp[s[i]]++;
  }

cout << "YES\n";
return;


  for(auto it: mp) {
  	if(mp1[it.first]) {
  		cout << "NO\n";return;
  	}
  }
  for(auto it: mp1) {
  	if(mp[it.first]) {
  		cout << "NO\n";return;
  	}
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