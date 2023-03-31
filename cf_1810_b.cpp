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
  if(n % 2 == 0) {
  	cout << "-1\n";
  	return;
  }

  int n1 = n;

  int t = log2(n1);
  // cout << t << '\n';
  vector<int> ans;
  while(n > 1){
    int temp1 = ((n + 1 ) / 2);
    int temp2 = ((n - 1 ) / 2);
    if(((n + 1 ) / 2) % 2 == 1){
      n = temp1;
      ans.pb(1);
      continue;
    }

    if(((n - 1 ) / 2) % 2 == 1){
      n = temp2;
      ans.pb(2);
      continue;
    }

    break;
  }

  if(n == 1) {
  	if(ans.size() > 40) {
  		cout << "-1\n";
  		return;
  	}
  	reverse(ans.begin(), ans.end());
  	cout << ans.size() << '\n';
  	pVec(ans);
  	return;
  }
  cout << "-1\n";

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