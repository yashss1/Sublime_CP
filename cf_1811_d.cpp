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

// https://www.autodraw.com/share/V7XY6OX55VXU
vector<int> fibo(45);
void fibonacci() {
	fibo[0] = 1;
	fibo[1] = 1;
	for(int i = 2; i <= 44; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}

int go(int n, int x, int y) {
	if(n == 1) {
		return 1;
	}
	if(y > fibo[n]) {
		y -= fibo[n];
		return go(n - 1, y, x);
	}
	else if(y <= fibo[n - 1]){
		return go(n - 1, y, x); // alternate axis
	}
	return false;
}

void yash()
{
  int n, a, b;
  cin >> n >> a >> b; 
  // pVec(fibo);
  if(go(n, a, b)) {
  	cout << "YES\n";
  	return;
  }
  cout << "NO\n";
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fibonacci();
  test
  yash();
  return 0;
}