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
  int n, k;
  cin >> n >> k; 
  // cout << n << " " << k << " -> ";
  int t = ((n) * (n + 1)) / 2;
  if(k == t) {
  	for(int i = 1; i <= n; i++) {
  		cout << i << " ";
  	}
  	cout << '\n';
  	return;
  }

  if(k == 0) {
  	for(int i = 1; i <= n; i++) {
  		cout << "-1 ";
  	}
  	cout << '\n';
  	return;
  }

  vector<int> temp(n + 1, 0);
  for(int i = 1; i <= n; i++) {
  	temp[i] = i;
  }

  int t1 = log2(k);
  // if((int)(pow(2ll, t1)) + 1ll == k) {
  // 	temp[t1 + 1] = 0;
  // 	for(int i = t1 + 2; i <= n; i++) {
  // 		temp[i] = -1000;
  // 	}
  // 	for(int i = 1; i <= n; i++) {
  // 		cout << temp[i] << ' ';
  // 	}
  // 	cout << "\n";
  // 	return;
  // }

  int t2 = (int)(pow(2ll, t1 + ((k == pow(2ll, log2(k))) ? 0 : 1))) + 1;
  // cout << t2 << "\n";
  int pos = t1 + ((k == pow(2ll, log2(k))) ? 1 : 2);
  int k1 = k;
  for(int i = 0; i < n; i++) {
  	// temp[i] = -1000;
  	if(k1 > 0){
        temp[i + 1] = 2 * (min(k1, n - i)) - 1;
        k1 -= min(k1, n - i);
    } else {
    	temp[i + 1] = -2;
    }
  }

  int tempp = t2 - k;
  int i = pos - 1;
  int sum = 0;
  while(tempp-- && i >= 0) {
  	sum += temp[i];
  	i--;
  }

  // temp[pos] = (-sum);
  for(int i = 1; i <= n; i++) {
  	cout << temp[i] << " ";
  }
  cout << "\n";


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

/*
1 2 3 4
_ _ _ _

0 all neg
1 1 -1 -3 -6
2 1 0 -3 -6
3 1 2 -3 -6
4 1 2 -2 -6
5 1 2 0 -6
6 1 2 3 -6
7 1 2 3 -5
8 1 2 3 -3
9 1 2 3 0
10 all pos

*/
