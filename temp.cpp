#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);

        }
        for (auto it : a) {
            mp[it]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]] > 0)
            {
                int x = (int)(2147483647) ^ (a[i]);
                if (mp[x] > 0)
                {
                    mp[x] -= 1;
                    ans += 1;
                }
            }
        }
        cout << n - ans << endl;
    }
}