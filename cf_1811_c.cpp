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
  vector<int> v(n - 1);
  for(int i = 0; i < n - 1; i++) {
  	cin >> v[i];
  }

  // reverse(v.begin(), v.end());

  vector<int> ans;

  vector<int> temp(n);
  for(int i = 1; i <= n - 1; i++) {
  	temp[i] = v[i - 1];
  	continue;
  	if(v[i - 1] >= v[i]) {
  		ans.push_back(v[i - 1]);
  	}
  	else {
  		if(ans.size() > 0 && ans[ans.size() - 1] == v[i - 1]) {
  			ans.push_back(v[i]);
  			continue;
  		}
  		ans.push_back(v[i - 1]);
  		ans.push_back(v[i - 1]);
  	}
  }

  for(int i = 2; i <= n - 1; i++) {
  	if(temp[i] < temp[i - 1]) {
  		temp[i - 2] = temp[i - 1];
  		temp[i - 1] = temp[i];
  	}
  }
  pVec(temp);

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