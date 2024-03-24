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

int n, p, k, x;
vector<int> v;

int go(int idx, int rem) {
    if (rem < 0) {
        return INT_MAX;
    }
    if (idx >= n) {
        return rem == 0 ? 0 : INT_MAX;
    }

    int c1 = (v[idx] * p) + go(idx + k + 1, rem - p);
    int c2 = (v[idx] * (x % p)) + go(idx + k + 1, rem - (x % p));
    int c3 = go(idx + 1, rem);

    return min({c1, c2, c3});
}

void yash()
{
    cin >> n >> p >> k >> x;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = go(0, x);
    cout << ans << '\n';
}

signed main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // test
    yash();
    return 0;
}