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

void yash()
{
    int k, q;
    cin >> k >> q;

    int time = 0;

    map<string, int> tokenTime;
    map<string, int> present;
    set<pair<int, string>> st;
    map<string, int> mp2;

    while (q--) {
        string s;
        cin >> s;
        if (s == "generate") {
            string a;
            int b;
            cin >> a >> b;
            tokenTime[a] = b;
            present[a] = 1;

            st.insert({b, a});
            mp2[a]++;
            time = b;
        }
        else if (s == "renew") {
            string a;
            int b;
            cin >> a >> b;
            if (present[a] == 0) {
                continue;
            }
            mp2[a]++;
            tokenTime[a] = b;
            st.insert({b, a});
            time = b;
        }
        else {
            int b;
            cin >> b;
            time = b;

            while (st.size() > 0) {
                pair<int, string> temp = (*st.begin());

                if (time - tokenTime[temp.second] >= k || tokenTime[temp.second] > temp.first) {
                    st.erase(st.find(temp));
                    mp2[temp.second]--;
                    if (mp2[temp.second] == 0) {
                        mp2.erase(temp.second);
                    }
                }
                else {
                    break;
                }
            }

            cout << mp2.size() << '\n';
        }
    }
    // cout << '\n';

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