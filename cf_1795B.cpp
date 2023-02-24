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
  int n, k;
  cin >> n >> k;

  vector<int> v(52, 0);
  for(int i = 0; i < n; i++) {
  	int l, r;
  	cin >> l >> r;
  	if(k > r || k < l) continue;
  	for(int j = l; j <= r; j++) {
  		v[j]++;
  	}
  } 

  if(v[k] == 0) {
  	cout << "NO\n";
  	return;
  }

  int mx = INT_MIN;
  map<int, int> mp;
  for(int i = 0; i <= 51; i++) {
  	mx = max(mx, v[i]);
  	mp[v[i]]++;
  }

  if(mx == v[k] && mp[mx] == 1) {
  	cout << "YES\n";
  	return;
  }
  cout << "NO\n";
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