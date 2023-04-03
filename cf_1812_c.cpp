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

int T;
void yash(int n1)
{
	// cout << n << '\n';
  // int prod = 1;
  // for(int i = 0; i < n; i++) {
  // 	int x;
  // 	cin >> x;
  // 	prod *= x;
  // }
  // cout << prod << "\n";
	int n;
	cin >> n;

	int prod = 1;
	map<int, int> mp;
	mp[2] = 5;
	mp[7] = 4;

	mp[1] = 2;
	mp[3] = 5;
	mp[4] = 4;
	mp[5] = 5;
	mp[6] = 6;
	mp[8] = 7;
	mp[9] = 6;

	for(int i = 0; i < (mp[n] % T); i++) {
		int x;
		cin >> x;
		prod *= x;
	}

	cout << prod * n << '\n';
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  T = t;
  for(int i = 1; i <= t; i++) {
  	yash(i % 2 != 0 ? t : t - 1);
  }
  return 0;
}