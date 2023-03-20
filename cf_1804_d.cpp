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
  int n, q;
  cin >> n >> q; 
  vector<int> v(n);
  vector<int> hsh(n + 1, 0);
  int sum = 0;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	hsh[i + 1] = hsh[i] + v[i];
  	sum += v[i];
  }

  while(q--) {
  	int l, r, k;
  	cin >> l >> r >> k;

  	int curr = sum - (hsh[r] - hsh[l - 1]);
  	curr  += (r - l + 1) * k;
  	if(curr % 2) {
  		cout << "YES\n";
  	}else {
  		cout << "NO\n";
  	}
  }
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