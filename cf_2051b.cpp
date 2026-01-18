//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

void yash()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c; 

	int temp = a + b + c;

	int ans = (n / temp) * 3;
	n %= (temp);

	if(n > 0) {
		n -= a;
		ans++;
	}
	if(n > 0) {
		n -= b;
		ans++;
	}
	if(n > 0) {
		n -= c;
		ans++;
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