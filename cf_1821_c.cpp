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
  int n = s.size();

  int ans = n - 1;
  for(int cc = 0; cc < 26; cc++) {
  	char c = 'a' + cc;

  	vector<int> temp;
  	for(int i = 0; i < n; i++) {
  		if(s[i] != c) {
  			temp.push_back(i);
  		}
  	} 
  	ans = min(ans, (int)temp.size());

    int curr = 1, temp2 = 1;
    for(int i = 1; i < (int)temp.size(); i++) {
    	if(temp[i] == temp[i - 1] + 1) {
    		temp2++;
    	}else {
    		temp2 = 1;
    	}
    	curr = max(curr, temp2);
    }
    cout << c << " " << curr << "\n";
 
    ans = min(ans, curr);
  }

  cout << ans << '\n';

  int anss = (ans == 0) ? (0) : ((int)log2(ans) + 1ll);

  cout << anss << "\n";
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
