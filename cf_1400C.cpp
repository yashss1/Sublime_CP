//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define ll               long long
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

ll n, m, k, x, q, a[N], b[N], ans;
void yash()
{
  string s; cin >> s;
    n = s.size();
    cin >> x;
    string t(n, '1');
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (i - x >= 0)
                t[i - x] = '0';
            if (i + x < n)
                t[i + x] = '0';
        }
    }
    string z = "";
    for (ll i = 0; i < n; i++)
    {
        ll b = 0;
        if (i - x >= 0)
        {
            if (t[i - x] == '1') b = 1;
        }
        if (i + x < n)
        {
            if (t[i + x] == '1') b = 1;
        }
        if (b)
        {
            z += '1';
        }
        else
        {
            z += '0';
        }
        if (z[i] != s[i])
        {
            cout << -1 << "\n";
            return ;
        }
    }
    cout << t << "\n";
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