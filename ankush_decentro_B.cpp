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
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> v(n);
  map<int, int> mp;

  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	mp[v[i]]++;
  } 

  int res = mp.size();
  vector<int> temp;
  for(auto it: mp) {
  	if(it.second % k == 0) {
  		temp.push_back(it.second / k);
  	}
  }
  sort(temp.begin(), temp.end());

  vector<int> hsh(temp.size());
  for(int i = 0; i < temp.size(); i++) {
  	hsh[i] = temp[i];
  	if(i > 0) {
  		hsh[i] += hsh[i - 1];
  	}
  }

  // pVec(hsh);
  // cout << res << '\n';

  while(q--) {
  	int x;
  	cin >> x;

  	if(hsh.size() == 0) {
  		cout << res	 << '\n';
  		continue;
  	}

  	int l = 0, r = hsh.size();
  	int idx = -1;
  	while(l <= r) {
  		int mid = (l + r) / 2;
  		if(hsh[mid] <= x) {
  			idx = mid;
  			l = mid + 1;
  		}
  		else {
  			r = mid - 1;
  		}
  	}

  	// cout << x << " " << idx << '\n'; 

  	if(idx == -1) {
  		cout << res << '\n';
  		continue;
  	}
  	if(idx >= hsh.size()) {
  		cout << res - hsh.size() << '\n';
  		continue;
  	}
  	cout << res - idx - 1 << '\n';
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