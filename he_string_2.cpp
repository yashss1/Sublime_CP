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
// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/string-queries-1/

void yash()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> hsh(26, vector<int> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            hsh[j][i + 1] = ((s[i] - 'a') == j) + hsh[j][i];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        vector<int> temp;
        for (int i = 0; i < 26; i++) {
            int t = hsh[i][r] - hsh[i][l - 1];
            if (t) {
                temp.push_back(t);
            }
        }
        sort(temp.begin(), temp.end());
        // pVec(temp);
        int Min = INT_MAX;
        for (int i = 0; i < temp.size(); i++) {
            Min = min(Min, r - l + 1 - temp[i] * ((int)temp.size() - i));
        }

        cout << Min << '\n';
    }

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