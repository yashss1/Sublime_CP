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
const int N = 19;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

string a, b;
int dp[2][2][2][10][10][N];
int go(int idx, int edgeBottom, int edgeTop, int mn, int mx, int gotNonZero) {
    if (idx == a.size()) {
        return mx - mn;
    }
 
  	int &ans = dp[edgeBottom][edgeTop][gotNonZero][mn][mx][idx];
  	if(ans != -1) {
  		return ans;
  	}

  	ans = INT_MAX;
 
    for (int i = 0; i < 10; i++) {
        if (edgeBottom && i < a[idx] - '0')continue;
        if (edgeTop && i > b[idx] - '0')continue;
 			
 		ans = min(ans, go(idx + 1, edgeBottom && (i == a[idx] - '0'), edgeTop && (i == b[idx] - '0'), min(mn, i), max(mx, i), gotNonZero || (i != 0)));
 		
    }
    return ans;
}

void trace(int idx, int edgeBottom, int edgeTop, int mn, int mx, int gotNonZero) {
    if (idx == a.size()) {
        return;
    }
 
  	int thatsit = dp[edgeBottom][edgeTop][gotNonZero][mn][mx][idx];
 
    for (int i = 0; i < 10; i++) {
        if (edgeBottom && i < a[idx] - '0')continue;
        if (edgeTop && i > b[idx] - '0')continue;
 			
 		int ans = go(idx + 1, edgeBottom && (i == a[idx] - '0'), edgeTop && (i == b[idx] - '0'), min(mn, i), max(mx, i), gotNonZero || (i != 0));
 		if(ans == thatsit) {
 			if(gotNonZero || (i != 0)) {
 				cout << i;
 			}
 			trace(idx + 1, edgeBottom && (i == a[idx] - '0'), edgeTop && (i == b[idx] - '0'), min(mn, i), max(mx, i), gotNonZero || (i != 0));
 			return;
 		}
 		
    }
    assert(false);
}

void yash()
{
  	cin >> a >> b;
  	if(a.size() == 1) {
    	cout << a << '\n';
    	return;
    }

    reverse(all(a));
    while (a.size() < b.size()) {
        a += "0";
    }
    reverse(all(a));
    memset(dp, -1, sizeof(dp));


    int ans = INT_MAX;
 
    for (int i = 0; i < 10; i++) {
        if (i < a[0] - '0')continue;
        if (i > b[0] - '0')continue;
 
        int temp = go(1, i == a[0] - '0', i == b[0] - '0', (i == 0) ? 9 : i, (i == 0) ? 0 : i, (i != 0));
        ans = min(ans, temp);
    }
    // cout << ans << "\n"; 

	for (int i = 0; i < 10; i++) {
        if (i < a[0] - '0')continue;
        if (i > b[0] - '0')continue;
 
        int temp = go(1, i == a[0] - '0', i == b[0] - '0', (i == 0) ? 9 : i, (i == 0) ? 0 : i, (i != 0));
        if(ans == temp) {
        	if(i != 0) {
        		cout << i;
        	}
        	trace(1, i == a[0] - '0', i == b[0] - '0', (i == 0) ? 9 : i, (i == 0) ? 0 : i, (i != 0));
        	cout << '\n';
        	return;
        }
    }    
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