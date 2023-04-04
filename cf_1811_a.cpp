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
  int n, k;
  cin >> n >> k; 
  string s;
  cin >> s;
  vector<char> ans;
  int flag = 0;
  for(int i = 0; i < n; i++) {
  	if(s[i] - '0' < k && flag == 0) {
  		ans.push_back('0' + k);
  		flag = 1;
  		i--;
  		continue;
  	}
  	ans.push_back(s[i]);
  }
  if(flag == 0) {
  	ans.push_back('0' + k);
  }
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