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
  int a, b;
  cin >> a >> b; 
  int diff = b - a;
  int ans = diff;

  for(int i = 0; i < diff; i++) {
  	int currA = a + i, currB = b;
  	currA |= currB;
  	if(currA == currB) {
  		ans = min(ans, i + 1);
  		continue;
  	}

  	ans = min(ans, (i + currA - currB + 1));
  }

  for(int i = 0; i < diff; i++) {
  	int currA = a, currB = b + i;
  	currA |= currB;
  	if(currA == currB) {
  		ans = min(ans, i + 1);
  		continue;
  	}

  	ans = min(ans, (i + currA - currB + 1));
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