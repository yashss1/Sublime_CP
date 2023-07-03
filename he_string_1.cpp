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

// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/aliceandstrings-9da62aa7/
void yash()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int prev = 0;
    for (int i = 0; i < n; i++) {
        int temp = b[i] - a[i];

        if (temp < 0) {
            cout << "NO\n";
            return;
        }
        if (prev > temp) {
            cout << "NO\n";
            return;
        }
        prev = temp;
    }
    cout << "YES\n";
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