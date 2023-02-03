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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<int> v(N);
int go(int idx, int prev) {
	int previous = v[idx - 1];

	if(prev == 1) {
		previous *= -1;
	}

	if(idx == n) {
		return previous;
	}

	int curr = v[idx];
	if(prev == 1) {
		curr *= -1;
	}

	// take then change or not change // dont take
	int c1 = 0, c2 = 0;
	if(curr == v[idx]) {
		c1 = (previous * -1) + go(idx + 1, 1); // change
	}else {
		c1 = (previous * -1) + go(idx + 1, 0); // dont change
	}

	if(curr == v[idx]) {
		c2 = previous + go(idx + 1, 1); // change
	}else {
		c2 = previous + go(idx + 1, 0); // dont change
	}	

	return max({c1, c2});
}

void yash()
{
  cin >> n; 
  int neg = 0, mn = 1e18, ans = 0;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	ans += abs(v[i]);
    mn = min(mn, abs(v[i]));
    if (v[i] < 0){
    	neg++;
    }
  }

  // int ans1 = go(1, 1);
  // int ans2 = go(1, 0);

  // // cout << ans1 << " " << ans2 << '\n';

  // cout << max({ans1, ans2}) << '\n';

  if(neg % 2) {
  	cout << ans - (2 * mn) << "\n";
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
  test
  yash();
  return 0;
}