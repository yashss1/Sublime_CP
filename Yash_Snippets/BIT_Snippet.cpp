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

struct BIT {
    int N;
    vector<int> bit;

    void init(int n) {
        N = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= N)  {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void updateMax(int idx, int val) {
        while (idx <= N) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int pref(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    int prefMax(int idx) {
        int ans = -2e9;
        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }

    int rsum(int l, int r) {
        return pref(r) - pref(l - 1);
    }
};

/*
6
1 4 3 2 5 6
*/

void yash()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // pVec(v);

    BIT bit;
    bit.init(n + 1);

    for (int i = 0; i < n; i++) {
        bit.update(i + 1, v[i]);
    }

    cout << bit.rsum(2, 5) << '\n';
    bit.update(4, 90 - 2); // the second parameter adds to current value. but i wanted to replace, so have minused the current element first
    cout << bit.rsum(2, 5) << '\n';
    for (int i = 1; i <= n; i++) {
        cout << i << " -> " << bit.rsum(i, i) << '\n';
    }


    cout << bit.prefMax(2) << '\n'; // max element till index 2
    cout << bit.prefMax(6) << '\n';
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