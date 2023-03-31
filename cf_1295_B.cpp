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
  string s;
  cin >> s;

  int zero = 0, one = 0;
  for(int i = 0; i < n; i++) {
  	if(s[i] == '0') {
  		zero++;
  	}
  	else {
  		one++;
  	}
  }

  // if(one > zero && k > 0) {
  // 	cout << "0\n";
  // 	return;
  // }
  // if(one < zero && k < 0) {
  // 	cout << "0\n";
  // 	return;
  // }
  // if(one == zero || k == 0) {
  // 	if(one == zero && k == 0) {
  // 		cout << "-1\n";
  // 		return;
  // 	}
  // 	if(one == zero) {
  // 		cout << "0\n";
  // 		return;
  // 	} 
  // 	cout << "1\n";
  // 	return;
  // }

  // if(k < 0) {
  // 	swap(one, zero);
  // 	for(int i = 0; i < n; i++) {
  // 		if(s[i] == '0') s[i] = '1';
  // 		else s[i] = '0';
  // 	}
  // 	k *= -1;
  // }
  
  int diff = zero - one;

  int sum = 0;
  int curr = 0, ans = 0;
  for(int i = 0; i < n; i++) {
  	if(diff != 0 && abs(k - curr) % abs(diff) == 0 && (k - curr) / (diff) >= 0) {
  		 ans++;
  	}
  	if(s[i] == '0') {
  		curr++;
  	}else {
  		curr--;
  	}

  	if(diff == 0) {
  		if(curr == k) {
  			cout << "-1\n";
  			return;
  		}
  	}
  }

  // cout << mod << '\n';
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