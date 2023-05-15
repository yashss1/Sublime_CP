//YashS
// DIGIT DP
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


int prime[N + 2] = {0};
void seive()
{
    for (int i = 2; i <= N; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}

string l, r;
int n, k;

int dp[2][2][11][100][4005];

int go(int idx, int edgeBottom, int edgeTop, int sum, int rem) {
    if (idx == n) {
        if (prime[sum] == 0 && rem == 0) {
            return 1;
        }
        return 0;
    }

    int &ans = dp[edgeBottom][edgeTop][idx][sum][rem];
    if (ans != -1) {
        return ans;
    }

    ans = 0;
    for (int i = 0; i < 10; i++) {
        if (edgeBottom && i < l[idx] - '0')continue;
        if (edgeTop && i > r[idx] - '0')continue;

        ans += (go(idx + 1, edgeBottom && (i == l[idx] - '0'), edgeTop && (i == r[idx] - '0'), sum + i, (rem * 10ll + i) % k));
    }
    return ans;
}

void yash() {
    memset(dp, -1, sizeof(dp));
    int a, b;
    cin >> a >> b >> k;
    l = to_string(a);
    r = to_string(b);

    cout << l << " " << r << '\n';
    if (k >= 4000) {
        // as number of factors now are less for O(N)
        int t = a / k;
        int x = (t) * k;
        if (x < a) {
            x += k;
        }

        int ans = 0;
        for (int i = x; i <= b; i += k) {
            int sum = 0;
            int n = i;
            while (n) {
                sum += (n % 10);
                n /= 10;
            }
            if (prime[sum] == 0) {
                ans++;
            }
        }

        ans %= MOD;

        cout << ans << '\n';
        return;
    }


    reverse(l.begin(), l.end());
    while (l.size() < r.size()) {
        l += "0";
    }
    reverse(l.begin(), l.end());
    n = r.size();

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (i < l[0] - '0')continue;
        if (i > r[0] - '0')continue;

        ans += (go(1, (i == l[0] - '0'), (i == r[0] - '0'), i, (i % k)));
    }

    ans = ans % MOD;
    cout << ans << '\n';
}

signed main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    seive();
    // test
    yash();
    return 0;
}