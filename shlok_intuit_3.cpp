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

int n, x, y;
vector<vector<int>> v;

int go(int mask, int prev, int isFirst) {
	if((1 << (n + 1)) - 1 == mask) {
		return v[prev+1][n+1] ;
	}

	int ans = 1e18;
	for(int i = 0; i < n + 1; i++) {
		if(isFirst == 1) {
			if(!((1 << i) & mask)) {
				ans = min(ans, v[0][i + 1] + go(mask ^ (1 << i), i, 0));
			}
		}
		else {
			if(!((1 << i) & mask)) {
				ans = min(ans, v[prev + 1][i + 1] + go(mask ^ (1 << i), i, 0));
			}
		}
	}

	return ans;
}

void yash()
{
  cin >> n >> x >> y; 
  v.assign(n + 3, vector<int>(n + 3));
  for(int i = 0; i < n + 2; i++) {
  	for(int j = 0; j < n + 2; j++) {
  		cin >> v[i][j];
  	}
  }

  int ans = x + ((2 * y) * go(0, 0, 1));
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