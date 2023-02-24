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
  vector<int> v(n);
  for(int i = 0; i < n * 2; i++) {
  	cin >> v[i];
  }

  set<int> left[2], right[2];

  for(int i = n - 1; i >= 0; i--) {
  	if(v[i] == 1) {
  		left[0].insert(i);
  	}
  	else {
  		left[1].insert(i);
  	}
  }

  for(int i = n; i < 2 * n; i++) {
  	if(v[i] == 1) {
  		right[0].insert(i);
  	}
  	else {
  		right[1].insert(i);
  	}
  }


  

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