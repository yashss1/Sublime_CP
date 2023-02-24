//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define ll                long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 998244353;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int fpow(int x, int y, int p = MOD) {
    x = x % p; int sum = 1; while (y) {
        if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
    } return sum;
}
ll fact[3000007] = {0};
    void facto() {
    fact[0] = 1; fact[1] = 1; for (int i = 2; i < 300000; i++)fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll ncr(ll n, ll r) {
    if (r > n)return 0;
    ll res = 1; res = fact[n]; res = (res * (fpow(fact[r], MOD - 2))) % MOD; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}
ll npr(ll n, ll r) {
    if (r > n)return 0;
    ll res = 1; res = fact[n]; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
 
void yash()
{
  int n;
  cin >> n; 
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  vector<map<int, int>> mp;
  for(int i = 0; i < n; i+=3) {
  	map<int, int> temp;
  	temp[v[i]]++;
  	temp[v[i + 1]]++;
  	temp[v[i + 2]]++;
  	mp.push_back(temp);
  }

  int ans = 1;
  for(int i = 0; i < mp.size(); i++) {
  	if(mp[i].size() == 3) continue;
  	if(mp[i].size() == 1) {
  		ans = mod_mul(ans, 3, MOD);
  		continue;
  	}

  	int mx = INT_MIN;
  	for(auto it: mp[i]) {
  		mx = max(mx, it.first);
  	}

  	int t = mp[i][mx];
  	if(t == 2) {
  		continue;
  	}
  	ans = mod_mul(ans, 2, MOD);
  }

  int t = (n / 3);
  ans = mod_mul(ans, ncr(t, t / 2), MOD);

  cout << ans << '\n';
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  facto();
  // test
  yash();
  return 0;
}
