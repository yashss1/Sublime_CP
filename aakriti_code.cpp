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
Question : Arrange in lexicographically increasing order of names, if names are same then descending order of the number.

6
khabarovsk 20
moscow 10
kazan 50
kazan 35
moscow 60
khabarovsk 40

3
4
6
1
5
2

*/
bool cmp(pair<string,int>&p1, pair<string,int>&p2){
    if(p1.first!=p2.first)return p1.first<p2.first;
    else{
      return p1.second>p2.second;
    }
}

void yash()
{
  int n;
  cin >> n; 
  vector<pair<string, int>> v(n);
  map<int, int> pos;
  for(int i = 0; i < n; i++) {
  	cin >> v[i].first >> v[i].second;
  	pos[v[i].second] = i;
  }

  sort(v.begin(), v.end(), cmp);

  vector<int> ans(n);	
  for(int i = 0; i < n; i++) {
  	ans[i] = pos[v[i].second] + 1;
  }

  for(int i = 0; i < n; i++) {
  	cout << ans[i] << '\n';
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