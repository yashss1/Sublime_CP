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
const int N = 5e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, k;
vector<int> cold(N), hot(N), v(N), temp;
int dp[N][N];

int go(int idx, int prev) {
	if(idx == n) {
		return 0;
	}

	int &ans = dp[idx][prev];
	if(ans != -1) {
		return ans;
	}

	// stay on same
	int c1 = cold[temp[idx]] + go(idx + 1, prev);

	// go to another
	// fuck ternary operators : 3hrs waste
	int c2 = ((prev == temp[idx]) ? hot[temp[idx]] : cold[temp[idx]]) + go(idx + 1, temp[idx - 1]);

	return ans = min({c1, c2});
}

void yash()
{
  cin >> n >> k; 
  for(int i = 0; i < n + 2; i++) {
  	for(int j = 0; j < k + 2; j++) {
  		dp[i][j] = -1;
  	}
  }
  temp.clear();
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }
  for(int i = 1; i <= k; i++) {
  	cin >> cold[i];
  }
  for(int i = 1; i <= k; i++) {
  	cin >> hot[i];
  }

  int ans = 0;
  temp.push_back(v[0]);
  for(int i = 1; i < n; i++) {
  	if(v[i] != v[i - 1]) {
  		temp.push_back(v[i]);
  	}
  	else {
  		ans += (hot[v[i]]);
  	}
  }
  // pVec(temp);
  n = temp.size();

  // cout << ans << ' ';


  ans += (cold[temp[0]]) + go(1, 0);
  cout << ans << "\n";
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