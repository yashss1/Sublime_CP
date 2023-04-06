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

string a, b;
int dp[2][20];

int go(int idx, int edgeTop) {
    if (idx == a.size()) {
        return 1;
    }
 
    int &ans = dp[edgeTop][idx];
    if (ans != -1) {
        return ans;
    }
 
    ans = 0;
 
    for (int i = 0; i < 10; i++) {
        if (edgeTop && i > b[idx] - '0')continue;
        if(i == 4) continue;
 
        ans += go(idx + 1, edgeTop && (i == b[idx] - '0'));
    }
    return ans;
}

int solve2(int n) {
	a = to_string(0);
	b = to_string(n);
	reverse(all(a));
    while (a.size() < b.size()) {
        a += "0";
    }
    reverse(all(a));
    memset(dp, -1, sizeof(dp));

    int ans = 0;
 
    for (int i = 0; i < 10; i++) {
        if (i > b[0] - '0')continue;
        if(i == 4) continue;
 
        int t = go(1, i == b[0] - '0');
        ans += t;
    }

    return ans - 1; // -1 for 0
}

void yash()
{
  int n;
  cin >> n; 

  // cout << 1e13 - countNumbersWith4(1e13) << "\n"; // this function was from gfg
  // in contest digit dp code not written, was submitted by [pict]
  // return;
  // for(int i = 1; i <= 100; i++) {
  // 	cout << i << " -> " << solve(i) << " " << solve2(i) << '\n';
  // }
  // return;

  int temp = 0;
  int l = 0, r = 1e14;
  while(l <= r) {
  	int mid = (l) + ((r - l) / 2);
  	if((solve2(mid)) >= n) {
  		r = mid - 1;
  		temp = mid;
  	}
  	else {
  		l = mid + 1;
  	}
  }
  
  cout << temp << '\n';
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