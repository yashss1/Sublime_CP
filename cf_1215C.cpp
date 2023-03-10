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
  string a, b;
  cin >> a >> b;

  vector<pair<int, int>> v;
  map<char, int> mp;
  for(int i = 0; i < n; i++) {
  	if(a[i] != b[i]) {
  		mp[a[i]]++, mp[b[i]]++;
  		v.push_back({i, a[i] - 'a'});
  	}
  }

  for(auto it: mp) {
  	if(it.second % 2) {
  		cout << "-1\n";
  		return;
  	}
  }

  map<int, vector<int>> mp1;
  for(auto it : v) {
  	// cout << it.first << " " << it.second << "\n";
  	mp1[it.second].push_back(it.first);
  }

  int ans = 0, flag = 0;
  vector<int> temp;
  vector<pair<int, int>> res;
  for(auto it: mp1) {
  	int i = 0;
  	ans += (it.second.size() / 2);
  	for(i = 0; i + 1 < it.second.size(); i+=2) {
  		res.push_back({it.second[i], it.second[i + 1]});
  	}

  	if(i < it.second.size()) {
  		temp.push_back(it.second[i]);
  	}
  }

  if(temp.size() == 2) {
  	ans += 2;
  	res.push_back({temp[0], temp[0]});
  	res.push_back({temp[0], temp[1]});
  }
  // cout << flag << '\n';
  cout << ans << "\n";
  for(auto it: res) {
  	cout << it.first + 1 << " " << it.second + 1 << '\n';
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