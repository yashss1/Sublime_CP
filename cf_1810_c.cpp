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
  int n, c, d;
  cin >> n >> c >> d; 
  vector<int> v(n);
  map<int, int> mp;
  int bigger_than_n = 0;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	mp[v[i]]++;
  }

  sort(all(v));
  set<int> st;
  int res = (n * c);
  if(mp[1] == 1) {
  	res -= c;
  }
  else {
  	res += d;
  }
  for(int i = 0; i < n; i++) {
  	st.insert(v[i]);
  	int t1 = (n - i - 1) * c; // remove all after
  	int t2 = (v[i] - st.size()) * d; // add missing
  	int t3 = ((i + 1) - st.size()) * c; // remove left
  	// cout << t1 << " " << t2 << " " << t3 << "\n";
  	res = min(res, t1 + t2 + t3);
  }
  int gone = 0;
  for(int i = 1; i < n; i++) {
  	gone += v[i] - v[i - 1] - 1;
  	// res = min(res, (gone * d) + (n - i) * c);
  	// cout << res << ' ';
  }

  for(auto it: mp) {
  	if(it.first > n) {
  		bigger_than_n += it.second;
  	}
  }

  vector<int> pref(2 * n + 1, 0), suff(2 * n + 1, 0), missing(2 * n + 1, 0);
  for(int i = 1; i <= 2 * n; i++) {
  	pref[i] = pref[i - 1] + max(0ll, mp[i] - 1);
  }

  for(int i = 1; i <= 2 * n; i++) {
  	suff[i] = suff[i - 1] + (mp[i]);
  }

  for(int i = 1; i <= 2 * n; i++) {
  	missing[i] = missing[i - 1] + (mp[i] == 0);
  }


  // pVec(pref);
  // pVec(suff);
  // pVec(missing);

  int ans = (n * c);
  if(mp[1] == 0) {
  	ans += d;
  }
  // ans = INT_MAX;
  for(int i = 1; i <= 2 * n; i++) {
  	// remove all greater than i
  	int c1 = (n - suff[i]) * c;	
  	// remove dups less than i
  	int c2 = pref[i] * c;

  	// add rem less than i
  	int c3 = missing[i] * d;

  	// if(i == 2) {
  		// cout << c1 << " " << c2 << " " << c3 << '\n';
  	// }

  	ans = min(ans, (c1 + c2 + c3));
  }
  cout << res << '\n';
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