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

// https://codeforces.com/gym/433004/problem/E

bool cmp(pair<int,int>&p1, pair<int,int>&p2){
    if(p1.first!=p2.first)return p1.first<p2.first;
    else{
      return p1.second<p2.second;
    }
}

void yash()
{
  int n;
  cin >> n; 
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++) {
  	int a, b;
  	cin >> a >> b;
  	v.push_back({a, b});
  }
  sort(v.begin(), v.end(), cmp);

  int done = 0;
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
  	// mp[v[i + 1].first - v[i].first]++;
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