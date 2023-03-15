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
  int n, k, d, w;
  cin >> n >> k >> d >> w; 
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  int totalIn = 0;
  int maxPow = 0;

  int ans = 0;
  for(int i = 0; i < n; i++) {
  	totalIn = 1;
  	maxPow = v[i] + w;
  	int j = 0;
  	// cout << v[i] << " -> ";
  	for(j = i + 1; j < n; j++) {
  		if(totalIn >= k || v[j] > maxPow) {
  			break;
  		}
  		// cout << v[j] << " ";
  		totalIn++;
  	}
  	// cout << maxPow << '\n';
  	maxPow += d;
  	while(j < n && v[j] <= maxPow && totalIn < k) {
  		totalIn++;
  		j++;
  	}
  	ans++;
  	i = j - 1;
  }

  cout << ans << '\n';
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