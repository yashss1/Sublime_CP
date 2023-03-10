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

// Home decor
void yash()
{
  int n, w, x, y;
  cin >> n >> w >> x >> y;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  map<int, int> mp;
  vector<int> hsh(n + 1, 0);
  for(int i = 0; i < n; i++) {
  	hsh[i + 1] = hsh[i] + v[i];
  	mp[hsh[i + 1]] = 1;
  }

  // pVec(hsh);
  for(int i = 0; i <= n; i++) {
  	int curr = hsh[i];

  	int w1 = curr + w;
  	int w2 = w1 + x;
  	int w3 = w2 + y;

  	if(mp[w1] == 1 && mp[w2] == 1 && mp[w3] == 1) {
  		cout << "YES\n";
  		return;
  	}

  	// cout << i << " -> " <<  w1 << " " << w2 << " " << w3 << '\n';
  }

  cout << "NO\n";

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

/*
01000101
00012222 type 1
00122222 type 2
*/




