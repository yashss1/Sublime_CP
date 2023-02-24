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
  string s;
  cin >> s;

  string a = "", b = "";
  int chance = 0;

  for(int i = 0; i < s.size(); i++) {
  	int t = s[i] - '0';
  	if(t % 2 == 0) {
  		a += ((t / 2) + '0');
  		b += ((t / 2) + '0');
  		continue;
  	}
  	
  	int t1 = (t / 2) + 1, t2 = t / 2;

  	if(chance % 2) {
  		a += (t1 + '0');
  		b += (t2 + '0');
  	}
  	else {
  		a += (t2 + '0');
  		b += (t1 + '0');
  	}
  	chance ^= 1;
  }

  int a1 = stoi(a);
  int b1 = stoi(b);

  cout << a1 << " " << b1 << '\n';
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
