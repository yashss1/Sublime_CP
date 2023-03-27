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
  int m;
  cin >> m; 
  map<int, int> mp;
  for(int i = 0; i < m; i++) {
  	int n; 
  	cin >> n;
  	vector<int> temp(n);
  	for(int j = 0; j < n; j++) {
  		cin >> temp[j];
  		mp[temp[j]] = i;
  	}
  }


  map<int, int> ans;
  for(auto it: mp) {
  	ans[it.second] = it.first;
  }	

  vector<int> res;
  for(int i = 0; i < m; i++) {
  	if(ans[i] == 0) {
  		cout << "-1\n";
  		return;
  	}
  	res.push_back(ans[i]);
  }


  pVec(res);
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