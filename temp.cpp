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

bool cmp(pair<vector<int>, int>&p1, pair<vector<int>, int>&p2) {
    if (p1.first.size() != p2.first.size()) return p1.first.size() > p2.first.size();
    else {
        return p1.first.size() < p2.first.size();
    }
}

void yash()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> multiples;
    for (int i = 1; i <= 26; i++) {
        if (n % i == 0) {
            multiples.push_back(i);
        }
    }

    // pVec(multiples);

    vector<pair<vector<int>, int>> mp(26);
    for (int i = 0; i < n; i++) {
        mp[s[i] - 'a'].first.push_back(i);
        mp[s[i] - 'a'].second = s[i] - 'a';
    }

    sort(all(mp), cmp);

    for (auto it : mp) {
        if (it.first.size() == 0) continue;
        pVec(it.first);
    } cout << "\n";

    vector<string> ans;
    for (int j = 0; j < multiples.size(); j++) {
        int freq = multiples[j];
        vector<pair<vector<int>, int>> m = mp;
        int flag = 1;
        vector<int> temp;

        for (int i = 0; i < 26; i++) {
            // cout << m[i].first.size() << " " << freq << '\n';
            // while (m[i].first.size() > freq) {
            //     temp.push_back(m[i].first[m[i].first.size() - 1]);
            //     mp[i].first.pop_back();
            // }
            while (m[i].first.size() < freq && temp.size() > 0) {
                m[i].first.push_back(temp[temp.size() - 1]);
                temp.pop_back();
            }
            if (m[i].first.size() < freq && m[i].first.size() != 0) {
                flag = 0;
                break;
            }
        }

        if (flag == 0) {
            continue;
        }

        cout << freq << " -> ";
        for (auto it : m) {
            if (it.first.size() == 0) continue;
            pVec(it.first);
        } cout << "\n";
        // string res(n, '#');
        // for (int i = 0; i < 26; i++) {
        //     for (auto it : m[i]) {
        //         res[it] = (char)('a' + i);
        //     }
        // }
        // ans.push_back(res);
    }

    pVec(ans);
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
