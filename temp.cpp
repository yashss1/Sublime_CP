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

#include <map>
template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;
public:
    // constructor associates whole range of K with val
    interval_map(V const& val) : m_valBegin(val) {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        // If the interval is empty, do nothing
        if (!(keyBegin < keyEnd)) return;

        // Case 1: Map is empty
        if (m_map.empty()) {
            m_map[keyBegin] = val;
            m_map[keyEnd] = m_valBegin;
            return;
        }

        // Case 2: keyBegin is greater than the last key in the map
        auto lastKey = m_map.rbegin()->first;
        if (keyBegin < lastKey) {

        }
        else {
            m_map[keyBegin] = val;
            m_map[keyEnd] = m_valBegin;
            return;
        }

        // Case 3: keyEnd is less than the first key in the map
        auto firstKey = m_map.begin()->first;
        if (keyEnd <= firstKey) {
            m_map[keyBegin] = val;
            m_map[keyEnd] = m_map.begin()->second;
            return;
        }

        // Case 4: Overlapping intervals
        auto itBegin = m_map.upper_bound(keyBegin);
        auto itEnd = m_map.upper_bound(keyEnd);

        // Update the value of the interval [keyBegin, itBegin->first)
        if (itBegin != m_map.begin()) {
            --itBegin;
            itBegin->second = val;
        }

        // Erase intervals inside the range [keyBegin, keyEnd)
        m_map.erase(itBegin, itEnd);

        // Insert new intervals
        m_map[keyBegin] = val;
        m_map[keyEnd] = (itEnd != m_map.end()) ? itEnd->second : m_valBegin;
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    }
};


void yash()
{
    int n;
    cin >> n;
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