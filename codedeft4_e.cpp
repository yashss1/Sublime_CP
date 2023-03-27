//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define ll               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> adj[N];
vector<int> v(N);
int dp[2][N];

int ans = 0;

int go(int curr, int parent, bool taken) {
	// int &ans = dp[taken][curr];
	// if (ans != -1) {
	// 	return ans;
	// }

	// ans = INT_MAX;
	// int temp = v[curr];
	// if(taken) {
	// 	temp ^= 1;
	// }

	int block2 = 0;
	// maybe precompute this
	for (auto child : adj[curr])
		if (child != parent) {
			block2 += go(child, curr, false);
		}
	
	if (block2 == 0) {
        return v[curr];
    }

    ans += block2;
    if(v[curr] == 1) {
    	if(block2 % 2 == 0) {
    		return 1;
    	}
    	return 0;
    }
    if(block2 % 2 == 0)  {
    	return 0;
    }
    return 1;

	for (auto child : adj[curr]) {
		if (child ^ parent) {
			if (!taken) {
				int c1 = (v[curr] == 1 || v[child] == 1) + go(child, curr, true);
				int add = block2 - (go(child, curr, false));
				ans = min(ans, c1 + add);
			}
		}
	}
	ans = min(ans, block2 + (v[curr] == 1));
	return ans; 
}

void yash()
{
  int n;
  cin >> n; 
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n - 1; i++) {
  	int u, v;
  	cin >> u >> v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  int flag = 0;
  for(int i = 1; i <= n; i++) {
  	cin >> v[i];
  	if(v[i] == 0) {
  		flag = 1;
  	}
  }

  // if(flag == 0) {
  // 	cout << "-1\n";
  // 	return;
  // }

  // cout << max(go(1, 1, true), go(1, 1, false)) << '\n';
  int t = go(1, -1, 0);
  if(t == 1) {
  	cout << "-1\n";
  	return;
  }
  cout << ans << "\n";
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