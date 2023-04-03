//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<"";cout<<"\n"
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
  map<int, int> mp;

  for(int i = 0; i < s.size(); i++) {
  	mp[s[i] - 'a']++;
  }

  // string ans = "";
  // for(int i = (s[0] - 'a'); i >= 0; i--) {
  // 	for(int j = 0; j < mp[i]; j++) {
  // 		ans.push_back((char)('a' + i));
  // 	}
 // 	mp[i] = 0;
  // } 

  // reverse(ans.begin(), ans.end());
  // string ans2 = "";
  // for(int i = 1; i < n; i++) {
  // 	if(mp[s[i] - 'a'] == 0) continue;
  // 	ans2.push_back(s[i]);
  // 	mp[s[i] - 'a']--;
  // }

  // // cout << ans << " " << ans2 << '\n';
  // ans += ans2;

  // for(int i = 0; i < n; i++) {
  // 	for(int j = s[i] - 'a' - 1; j >= 0; j--) {
  // 		if(mp[j] > 0) {
  // 			ans.push_back('a' + j);
  // 			flag = 1;
  // 		}
  // 	}
  // }



  string s1 = s;
  sort(all(s1));
  char c = 'z';
  int idx = -1;
  vector<char> ans, ans1;
  for(int i = 0; i < n; i++) {
  	c = min(c, s[i]);
  	if(c == s[i]) {
  		idx = i;
  	}
  }

  cout << c;
  for(int i = 0; i < n; i++) {
  	if(i != idx) {
  		cout << s[i];
  	}
  }
  cout << '\n';
  return;

  if(idx == -1) {
  	cout << s << '\n';
  	return;
  }

  int flag = 0;
  for(int j = n - 1; j >= idx; j--) {
  	if(c == s[j] && flag == 0) {
  		flag = 1;
  		continue;
  	}
  	ans1.push_back(s[j]);
  }
  reverse(all(ans1));

  for(auto it: ans1) {
  	ans.push_back(it);
  }
  // cout << ans << "\n";
  pVec(ans);
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
