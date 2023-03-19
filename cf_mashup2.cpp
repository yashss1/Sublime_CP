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

// https://codeforces.com/gym/433004/problem/B
void yash()
{
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	mp[v[i]]++;
  }

  int mx = INT_MIN;
  for(auto it: mp) {
  	mx = max(mx, it.second);
  } 

  for(int i = 0; i < n; i++) {
  	if(mp[v[i]] == mx) {
  		mx = v[i];
  		break;
  	}
  }

  vector<vector<int>> ans;
  vector<int> vis(n +  1, 0);
  // cout << mx << '\n';
  for(int i = 0; i < n; i++) {
  	if(v[i] == mx) {
  		int ii = i - 1;
  		vis[i] = 1;
  		while(ii >= 0 && vis[ii] == 0) {
  			vector<int> temp;
  			if(v[ii] > mx) {
  				temp = {2, ii + 1, ii + 1 + 1};
  			} else {
  				temp = {1, ii + 1, ii + 1 + 1};
  			}
  			
  			ans.push_back(temp);
  			vis[ii] = 1;
  			ii--;
  		}

  		ii = i + 1;
  		while(ii < n && v[ii] != mx && vis[ii] == 0) {
  			vector<int> temp;
  			if(v[ii] > mx) {
  				temp = {2, ii + 1, ii};
  			} else {
  				temp = {1, ii + 1, ii};
  			}
  			ans.push_back(temp);
  			vis[ii] = 1;
  			ii++;
  		}
  	} 
  }

  cout << ans.size() << "\n";
  for(auto it: ans) {
  	pVec(it);
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