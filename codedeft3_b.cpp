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

vector<int> v(4);

int go(int idx, int prev) {
	if(idx == 4) {
		return 0;
	}

	int c1 = 0, c2 = 0;
	if(prev == 1) {
		c2 = go(idx + 1, 0);
	}
	else {
		c1 = v[idx] + go(idx + 1, 1);
		c2 = go(idx + 1, 0);
	}

	return max({c1, c2});
}
void yash()
{
  for(int i = 0; i < 4; i++) {
  	cin >> v[i];
  }
  int ans = go(0, 0);
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