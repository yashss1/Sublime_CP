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
const int N = 1e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<vector<int>> factors;
unordered_map<int, int> mp;
vector<int> preCompute(int k) {
	// for(int i = 1; i <= N; i++) {
	// 	for(int j = i; j <= N; j+= i) {
	// 		if(mp[j] == 0) continue;
	// 		factors[j].push_back(i);
	// 	}
	// }
	vector<int> temp;
	for(int i = 1; i * i <= k; i++) {
		if(k % i == 0) {
			temp.push_back(i);
			if(k / i != i) {
				temp.push_back(k / i);
			}
		}
	}
	return temp;
}

int n;
vector<int> v(N);
vector<int> dp(N, 0);

void go(int i) {
	if(i == n) {
		return;
	}

	vector<int> temp = preCompute(v[i]);
	sort(temp.begin(), temp.end(), greater<int>());
	for(int j = 0; j < temp.size(); j++) {
		dp[temp[j]] = ((dp[temp[j]] % MOD) + (dp[temp[j] - 1] % MOD) % MOD);
  	}

  	go(i + 1);
}

void yash()
{
  
  cin >> n; 
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	mp[v[i]] = 1;
  }

  // preCompute();

  // for(int i = 0; i < n; i++) {
  	// cout << v[i] << " -> ";
  	// pVec(factors[v[i]]);
  // }
  // cout << "\n\n";

  dp[0] = 1;
  go(0);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
  	// cout << i << " -> " << dp[i] << '\n';
  	ans = ((ans % MOD) + (dp[i] % MOD)) % MOD;
  }
  cout << ans << '\n';
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  factors.resize(N);
  // test
  yash();
  return 0;
}