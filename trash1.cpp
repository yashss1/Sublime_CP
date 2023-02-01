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

/*
Given two binary strings s & t, rearange bits of t such that XOR of S and T is maximum

0011110
1111000

ans -> 1111101
*/

void yash()
{
  string s, t, ans;
  cin >> s >> t;

  map<char, int> mp;
  for(int i = 0; i < t.size(); i++) {
  	mp[t[i]]++;
  }

  for(int i = 0; i < s.size(); i++) {
  	if(s[i] == '1') {
  		if(mp['0'] > 0) {
  			ans.push_back('1');
  			mp['0']--;
  		}
  		else {
  			ans.push_back('0');
  			mp['1']--;
  		}
  	}
  	else {
  		if(mp['1'] > 0) {
  			ans.push_back('1');
  			mp['1']--;
  		}
  		else {
  			ans.push_back('0');
  			mp['0']--;
  		}
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
  // test
  yash();
  return 0;
}