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
const int N = 1e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int isPrime(int n) {
    rep(i, 2, ceil(sqrt(n)) + 1) {
        if (n % i == 0)return 0;
    }
    return 1;
}

int isPow(int n) {
    while (n > 1) {
        if (n % 3 == 1) {
            return 0;
        }
        n /= 3;
    }
    return (n == 1);
}

vector<int> v;

int dp[N];
int go(int idx) {
    if (idx >= 1000) {
        return 0;
    }
    if (idx == 1000) {
        return 0;
    }

    int &ans = dp[idx];
    if (ans != -1) {
        return ans;
    }
    int c1 = v[idx] + go(idx + 1);
    int c2 = v[idx] + go(idx + 2);

    return ans = min({c1, c2});
}


void yash()
{
    // int n;
    // cin >> n;
    // int ans = -1;
    // int i = 2;
    // while (n > 0) {
    //     string s = to_string(i);
    //     string s1 = s;
    //     reverse(all(s));
    //     int t = stoi(s);

    //     if (isPrime(t) && isPrime(i) && s != s1) {
    //         ans = i;
    //         n--;
    //     }
    //     i++;
    // }

    // cout << ans << '\n';

    // int n;
    // cin >> n;

    // int k = 0;
    // for (int i = 1; i <= n; i++) {
    //     int sum = 0;
    //     for (int j = 0; j < i; j++) {
    //         sum += k;
    //         k += 2;
    //     }
    //     if (i == n) {
    //         cout << sum << '\n';
    //     }
    // }

    // int n = 1261;
    // while (1) {
    //     string s = to_string(n);
    //     vector<int> v;
    //     if (s.size() % 2 == 0) {
    //         if (isPow(n)) {

    //         }
    //     }
    //     n++;
    // }

    memset(dp, -1, sizeof(dp));

    int k = 2;
    v.push_back(k);
    while (v.size() < 1000) {
        if (isPrime(k)) {
            v.push_back(k);
        }
        k++;
    }

    int ans = go(0);
    int ans1 = go(1);

    cout << min(ans, ans1) << '\n';
    // pVec(v);

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