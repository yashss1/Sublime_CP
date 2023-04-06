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

int n, k;
vector<int> v(N);
map<int, vector<int>> links;
int curr_k;

int go(int idx, int taken_k, int times_remain) {
	if(idx == n) {
		return (times_remain == 0) && (taken_k == 0 || taken_k == curr_k);
	}

	int c1 = 0, c2 = 0;
	if(taken_k == curr_k || taken_k == 0) {
		// now i have option to choose any element
		// take this
		// if(links[idx] != 0 && times_remain > 0) {
		// 	c1 = go(links[idx] - 1, curr_k - 1, times_remain - 1);
		// }
		for(auto it: links[idx]) {
			if(times_remain > 0) {
				c1 += go(it - 1, curr_k - 1, times_remain - 1);
			}
		}

		// dont take this
		c2 = go(idx + 1, curr_k, times_remain);
	}
	else {
		// go to next instance of this element
		// if(links[idx] != 0) {
		// 	c1 = go(links[idx] - 1, taken_k - 1, times_remain);
		// }
		// cout << idx << " -> " << taken_k << '\n';
		// pVec(links[idx]);
		// if(links[idx].size() == 0 && taken_k == 1) {
		// 	c1 = go(idx + 1, taken_k - 1, times_remain);
		// }
		for(auto it: links[idx]) {
			c1 += go(it - 1, taken_k - 1, times_remain);
		}
	}

	return c1 + c2;
}

void yash()
{
  cin >> n >> k; 
  links.clear();
  v.assign(n, 0);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  } 


  // step1 : link each element to it's next occurence
  vector<int> adj[n + 1];
  for(int i = n - 1; i >= 0; i--) {
  	if(adj[v[i]].size() == 0) {
  		links[i] = {};
  	}
  	else {
  		links[i] = adj[v[i]];
  	}
  	adj[v[i]].push_back(i + 1);
  }

  for(int i = 0; i < n; i++) {
  	sort(links[i].begin(), links[i].end());
  	cout << i + 1 << " -> ";
  	pVec(links[i]);
  }

  int ans = 1;
  for(int i = 0; i <= n; i+=k) {
  	curr_k = i / k;
  	// m = i
  	int temp = go(0, curr_k, curr_k);
  	cout << i << " -> " << curr_k << " | " << temp << '\n';
  	if(temp > 0) {
  		ans = temp;
  	}
  }

  cout << ans << '\n';

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